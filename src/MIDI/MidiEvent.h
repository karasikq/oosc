#ifndef MIDIEVENT_H
#define MIDIEVENT_H

#include <cstdint>

struct MidiEvent
{
    enum class EventType
    {
        NoteOff,
        NoteOn,
        Other
    };
    MidiEvent(EventType _event, uint8_t _key, uint8_t _velocity, uint32_t _deltaTick, uint32_t _absoluteTime) :
        event(_event), key(_key), velocity(_velocity), deltaTick(_deltaTick), absoluteTime(_absoluteTime) { }
    MidiEvent(EventType _event) : event(_event) { }

    EventType event;
    bool called = false;
    uint8_t key = 0;
    uint8_t velocity = 0;
    uint32_t deltaTick = 0;
    uint32_t absoluteTime = 0;
};

#endif // MIDIEVENT_H
