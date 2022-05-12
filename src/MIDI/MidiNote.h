#ifndef MIDINOTE_H
#define MIDINOTE_H

#include <cstdint>

struct MidiNote
{
    MidiNote() { }
    MidiNote(uint8_t _key, uint8_t _velocity, uint32_t _startTime, uint32_t _duration) :
        key(_key), velocity(_velocity), startTime(_startTime), duration(_duration) { }

    uint8_t key = 0;
    uint8_t velocity = 0;
    uint32_t startTime = 0;
    uint32_t duration = 0;
};

#endif // MIDINOTE_H
