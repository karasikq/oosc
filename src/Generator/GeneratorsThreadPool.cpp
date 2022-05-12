#include "GeneratorsThreadPool.h"
#include <iostream>

GeneratorsThreadPool::GeneratorsThreadPool(uint32_t threadsCount) {
  threads.reserve(threadsCount);
  for (uint32_t i = 0; i < threadsCount; ++i) {
    threads.emplace_back(&GeneratorsThreadPool::workerThread, this);
    threadsState[threads.back().get_id()] = ThreadState::Disabled;
  }
}

GeneratorsThreadPool::~GeneratorsThreadPool() {
  quite = true;
  {
    std::unique_lock<std::mutex> executionLock(executionMtx);
    for (auto &thread : threads) {
      threadsState[thread.get_id()] = ThreadState::Waiting;
    }
  }
  executionCv.notify_all();
  for (uint32_t i = 0; i < threads.size(); ++i) {
    threads[i].join();
  }
}

void GeneratorsThreadPool::terminate(uint32_t thread) {
  {
    std::unique_lock<std::mutex> executionLock(executionMtx);
    threadsState[threads[thread].get_id()] = ThreadState::Disabled;
  }
}

void GeneratorsThreadPool::executeAndWait() {
  {
    std::unique_lock<std::mutex> executionLock(executionMtx);
    for (auto &thread : threads) {
      threadsState[thread.get_id()] = ThreadState::Waiting;
    }
  }
  executionCv.notify_all();

  std::unique_lock<std::mutex> lock(completedThreadsMtx);
  completedThreadsCv.wait(lock, [this]() -> bool {
    bool completed = true;
    for (auto &thread : threads) {
      auto state = threadsState[thread.get_id()];
      if (state != ThreadState::Completed) {
        completed = false;
        break;
      }
    }
    return completed;
  });
}

void GeneratorsThreadPool::workerThread() {
  while (!quite) {
    std::unique_lock<std::mutex> executionLock(executionMtx);
    executionCv.wait(executionLock, [this]() -> bool {
      return threadsState[std::this_thread::get_id()] == ThreadState::Waiting;
    });

    if (!quite) {
      for (auto &threadTask : tasks[std::this_thread::get_id()]) {
        threadTask.second();
      }
    }

    {
      std::unique_lock<std::mutex> lock(completedThreadsMtx);
      threadsState[std::this_thread::get_id()] = ThreadState::Completed;
    }
    completedThreadsCv.notify_all();
  }
}
