//===-------------------- GeneratorsThreadPool.h -----------------*- C++-*-===//
//===-------------- GeneratorsThreadPool class definition------------------===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the GeneratorsThreadPool class, which
/// create thread pool for infinite execution generators in defined thread.
///
//===----------------------------------------------------------------------===//

#ifndef GENERATORSTHREADPOOL_H
#define GENERATORSTHREADPOOL_H

#include <atomic>
#include <functional>
#include <future>
#include <iostream>
#include <map>
#include <mutex>
#include <thread>
#include <unordered_set>
#include <vector>

/// Generators Thread Pool
class GeneratorsThreadPool {
public:
  /// Construct thread pool 
  GeneratorsThreadPool(uint32_t threadsCount);
  /// Default Destructor
  /// Terminate all threads
  ~GeneratorsThreadPool();

  /// State of the thread
  enum ThreadState { Completed, Waiting, Disabled };

  /// Add task to thread
  /// @threadId is an index of thread in thread pool
  template <typename Func, typename... Args>
  uint64_t addTask(uint32_t threadId, const Func &task, Args &&...args) {
    uint64_t taskId = lastTaskId++;
    tasks[threads[threadId].get_id()][taskId] = std::bind(task, args...);
    return taskId;
  }

  /// Terminate thread
  void terminate(uint32_t thread);
  /// Execute all tasks in threads
  void executeAndWait();

private:
  /// Function execute infinitly
  void workerThread();
  /// Threads tasks
  std::map<std::thread::id, std::map<uint32_t, std::function<void()>>> tasks;

  /// Mutex for thread
  std::mutex executionMtx;
  std::condition_variable executionCv;

  /// States of threads
  std::map<std::thread::id, ThreadState> threadsState;
  std::condition_variable completedThreadsCv;
  std::mutex completedThreadsMtx;

  /// Vector of threads
  std::vector<std::thread> threads;

  /// Atomic for terminate threads
  std::atomic<bool> quite{false};
  /// Last task id
  std::atomic<uint64_t> lastTaskId = 0;
};

#endif // GENERATORSTHREADPOOL_H
