#ifndef MIDITRACK_H
#define MIDITRACK_H

#include <string>
#include <vector>
#include <iostream>

#include "MidiEvent.h"
#include "MidiNote.h"

class MidiTrack
{
public:
    MidiTrack() { };
    ~MidiTrack() { };
    std::string name;
    std::string instrument;
    std::vector<MidiEvent> Events;
    std::vector<MidiNote> Notes;
    uint8_t maxNote = 64;
    uint8_t minNote = 64;

    friend std::ostream& operator<<(std::ostream& os, const MidiTrack& track)
    {
        os << "Track: " << track.name << "\nInstrument: " << track.instrument << std::endl;
        os << "Event\tKey\tVelocity\tDeltaTick" << std::endl;
        for(MidiEvent event : track.Events)
        {
            os << (uint32_t)event.event << "\t" << (uint32_t)event.key << "\t" << (uint32_t)event.velocity << "\t" << (uint32_t)event.deltaTick << std::endl;
        }
        return os;
    }
};

#endif // MIDITRACK_H
