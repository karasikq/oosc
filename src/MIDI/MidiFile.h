#ifndef MIDIFILE_H
#define MIDIFILE_H

#include <fstream>
#include <cstdint>
#include <string>
#include <vector>

#include "MidiTrack.h"

class MidiFile
{
public:
    enum EventName : uint8_t
    {
        VoiceNoteOff = 0x80,
        VoiceNoteOn = 0x90,
        VoiceAftertouch = 0xA0,
        VoiceControlChange = 0xB0,
        VoiceProgramChange = 0xC0,
        VoiceChannelPressure = 0xD0,
        VoicePitchBend = 0xE0,
        SystemExclusive = 0xF0
    };

    enum MetaEventName : uint8_t
    {
        MetaSequence = 0x00,
        MetaText = 0x01,
        MetaCopyright = 0x02,
        MetaTrackName = 0x03,
        MetaInstrumentName = 0x04,
        MetaLyrics = 0x05,
        MetaMarker = 0x06,
        MetaCuePoint = 0x07,
        MetaChannelPrefix = 0x20,
        MetaEndOfTrack = 0x2F,
        MetaSetTempo = 0x51,
        MetaSMPTEOffset = 0x54,
        MetaTimeSignature = 0x58,
        MetaKeySignature = 0x59,
        MetaSequencerSpecific = 0x7F,
    };

    MidiFile();
    MidiFile(const std::string& fileName);
    MidiFile(const MidiFile& other);
    MidiFile(MidiFile&& other);
    ~MidiFile();

    std::vector<MidiTrack> Tracks;

    uint32_t tempo = 0;
    uint32_t BPM = 120;
    uint32_t ppq = 24;
    uint32_t timeSignatureMult = 16;

    bool printMetaMessages = true;

    void Clear();
    bool Parse(const std::string& fileName);

protected:
    inline uint16_t BigToLittleEndian16(uint16_t n) { return ((n >> 8) | (n << 8)); }
    inline uint32_t BigToLittleEndian32(uint32_t n) { return (((n >> 24) & 0xff) | ((n << 8) & 0xff0000) | ((n >> 8) & 0xff00) | ((n << 24) & 0xff000000)); }
    std::string ReadString(std::ifstream& ifs, uint32_t length);
    uint32_t ReadValue(std::ifstream& ifs);

    friend std::ostream& operator<<(std::ostream& os, const MidiFile& track);
};

#endif // MIDIFILE_H
