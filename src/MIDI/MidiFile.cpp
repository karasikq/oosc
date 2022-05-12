#include <algorithm>
#include <iostream>

#include "MidiFile.h"

MidiFile::MidiFile() {}

MidiFile::MidiFile(const std::string &fileName) { Parse(fileName); }

MidiFile::~MidiFile() { Tracks.clear(); }

std::string MidiFile::ReadString(std::ifstream &ifs, uint32_t length) {
  std::string s;
  s.reserve(length);
  for (uint32_t i = 0; i < length; i++)
    s += ifs.get();
  return s;
}

uint32_t MidiFile::ReadValue(std::ifstream &ifs) {
  uint32_t value = 0;
  uint8_t currentByte = 0;

  value = ifs.get();

  if (value & 0x80) {
    value &= 0x7F;
    do {
      currentByte = ifs.get();
      value = (value << 7) | (currentByte & 0x7F);
    } while (currentByte & 0x80);
  }
  return value;
}

bool MidiFile::Parse(const std::string &fileName) {
  std::ifstream ifs;
  ifs.open(fileName, std::fstream::in | std::ios::binary);
  if (!ifs.is_open()) {
    std::cerr << "Cannot open file!" << std::endl;
    return false;
  }

  uint32_t n32 = 0;
  uint16_t n16 = 0;

  ifs.read((char *)&n32, sizeof(uint32_t));
  uint32_t chunkType = BigToLittleEndian32(n32);
  ifs.read((char *)&n32, sizeof(uint32_t));
  uint32_t headerLength = BigToLittleEndian32(n32);
  ifs.read((char *)&n16, sizeof(uint16_t));
  uint16_t format = BigToLittleEndian16(n16);
  ifs.read((char *)&n16, sizeof(uint16_t));
  uint16_t trackChunksCount = BigToLittleEndian16(n16);
  ifs.read((char *)&n16, sizeof(uint16_t));
  uint16_t division = BigToLittleEndian16(n16);

  for (uint16_t currentChunk = 0; currentChunk < trackChunksCount;
       currentChunk++) {
    ifs.read((char *)&n32, sizeof(uint32_t));
    uint32_t trackIndex = BigToLittleEndian32(n32);
    ifs.read((char *)&n32, sizeof(uint32_t));
    uint32_t trackLength = BigToLittleEndian32(n32);

    bool bEndOfTrack = false;

    Tracks.push_back(MidiTrack());

    uint32_t absoluteTime = 0;

    uint8_t nPreviousStatus = 0;

    while (!ifs.eof() && !bEndOfTrack) {
      uint32_t statusDeltaTime = 0;
      uint8_t status = 0;

      statusDeltaTime = ReadValue(ifs);
      absoluteTime += statusDeltaTime;

      status = ifs.get();

      if (status < 0x80) {
        status = nPreviousStatus;
        ifs.seekg(-1, std::ios_base::cur);
      }

      if ((status & 0xF0) == EventName::VoiceNoteOff) {
        nPreviousStatus = status;
        uint8_t channel = status & 0x0F;
        uint8_t noteID = ifs.get();
        uint8_t noteVelocity = ifs.get();
        Tracks[currentChunk].Events.push_back({MidiEvent::EventType::NoteOff,
                                               noteID,
                                               noteVelocity,
                                               statusDeltaTime,
                                               absoluteTime});
      } else if ((status & 0xF0) == EventName::VoiceNoteOn) {
        nPreviousStatus = status;
        uint8_t channel = status & 0x0F;
        uint8_t noteID = ifs.get();
        uint8_t noteVelocity = ifs.get();
        if (noteVelocity == 0)
          Tracks[currentChunk].Events.push_back({MidiEvent::EventType::NoteOff,
                                                 noteID,
                                                 noteVelocity,
                                                 statusDeltaTime,
                                                 absoluteTime});
        else
          Tracks[currentChunk].Events.push_back({MidiEvent::EventType::NoteOn,
                                                 noteID,
                                                 noteVelocity,
                                                 statusDeltaTime,
                                                 absoluteTime});
      } else if ((status & 0xF0) == EventName::VoiceAftertouch) {
        nPreviousStatus = status;
        uint8_t channel = status & 0x0F;
        uint8_t noteID = ifs.get();
        uint8_t noteVelocity = ifs.get();
        Tracks[currentChunk].Events.push_back({MidiEvent::EventType::Other});
      } else if ((status & 0xF0) == EventName::VoiceControlChange) {
        nPreviousStatus = status;
        uint8_t channel = status & 0x0F;
        uint8_t controlID = ifs.get();
        uint8_t controlValue = ifs.get();
        Tracks[currentChunk].Events.push_back({MidiEvent::EventType::Other});
      } else if ((status & 0xF0) == EventName::VoiceProgramChange) {
        nPreviousStatus = status;
        uint8_t channel = status & 0x0F;
        uint8_t programID = ifs.get();
        Tracks[currentChunk].Events.push_back({MidiEvent::EventType::Other});
      } else if ((status & 0xF0) == EventName::VoiceChannelPressure) {
        nPreviousStatus = status;
        uint8_t channel = status & 0x0F;
        uint8_t channelPressure = ifs.get();
        Tracks[currentChunk].Events.push_back({MidiEvent::EventType::Other});
      } else if ((status & 0xF0) == EventName::VoicePitchBend) {
        nPreviousStatus = status;
        uint8_t channel = status & 0x0F;
        uint8_t nLS7B = ifs.get();
        uint8_t nMS7B = ifs.get();
        Tracks[currentChunk].Events.push_back({MidiEvent::EventType::Other});

      } else if ((status & 0xF0) == EventName::SystemExclusive) {
        nPreviousStatus = 0;

        if (status == 0xFF) {
          uint8_t metaType = ifs.get();
          uint8_t metaLength = ReadValue(ifs);

          switch (metaType) {
          case MetaSequence:
            if (printMetaMessages)
              std::cout << "Sequence Number: " << ifs.get() << ifs.get()
                        << std::endl;
            break;
          case MetaText:
            if (printMetaMessages)
              std::cout << "Text: " << ReadString(ifs, metaLength) << std::endl;
            break;
          case MetaCopyright:
            if (printMetaMessages)
              std::cout << "Copyright: " << ReadString(ifs, metaLength)
                        << std::endl;
            break;
          case MetaTrackName:
            Tracks[currentChunk].name = ReadString(ifs, metaLength);
            if (printMetaMessages)
              std::cout << "Track Name: " << Tracks[currentChunk].name
                        << std::endl;
            break;
          case MetaInstrumentName:
            Tracks[currentChunk].instrument = ReadString(ifs, metaLength);
            if (printMetaMessages)
              std::cout << "Instrument Name: "
                        << Tracks[currentChunk].instrument << std::endl;
            break;
          case MetaLyrics:
            if (printMetaMessages)
              std::cout << "Lyrics: " << ReadString(ifs, metaLength)
                        << std::endl;
            break;
          case MetaMarker:
            if (printMetaMessages)
              std::cout << "Marker: " << ReadString(ifs, metaLength)
                        << std::endl;
            break;
          case MetaCuePoint:
            if (printMetaMessages)
              std::cout << "Cue: " << ReadString(ifs, metaLength) << std::endl;
            break;
          case MetaChannelPrefix:
            if (printMetaMessages)
              std::cout << "Prefix: " << ifs.get() << std::endl;
            break;
          case MetaEndOfTrack:
            bEndOfTrack = true;
            break;
          case MetaSetTempo:
            // Microseconds per quarter note
            if (tempo == 0) {
              (tempo |= (ifs.get() << 16));
              (tempo |= (ifs.get() << 8));
              (tempo |= (ifs.get() << 0));
              BPM = (60000000 / tempo);
              if (printMetaMessages)
                std::cout << "Tempo: " << tempo << " (" << BPM << "bpm)"
                          << std::endl;
            }
            break;
          case MetaSMPTEOffset:
            if (printMetaMessages)
              std::cout << "SMPTE Offset:\n\tH:" << ifs.get()
                        << " M:" << ifs.get() << " S:" << ifs.get()
                        << " FR:" << ifs.get() << " FF:" << ifs.get()
                        << std::endl;
            break;
          case MetaTimeSignature:
            if (printMetaMessages) {
              timeSignatureMult = ifs.get() * (2 << ifs.get());
              std::cout << "Time Signature: " << timeSignatureMult << std::endl;
              ppq = ifs.get();
              std::cout << "ClocksPerTick: " << ppq << std::endl;
              std::cout << "32per24Clocks: " << ifs.get() << std::endl;
            }
            break;
          case MetaKeySignature:
            if (printMetaMessages) {
              std::cout << "Key Signature: " << ifs.get() << std::endl;
              std::cout << "Minor Key: " << ifs.get() << std::endl;
            }
            break;
          case MetaSequencerSpecific:
            if (printMetaMessages)
              std::cout << "Sequencer Specific: " << ReadString(ifs, metaLength)
                        << std::endl;
            break;
          default:
            if (printMetaMessages)
              std::cout << "Unrecognised MetaEvent: " << metaType << std::endl;
          }
        }

        if (status == 0xF0) {
          std::cout << "System Exclusive Begin: "
                    << ReadString(ifs, ReadValue(ifs)) << std::endl;
        }

        if (status == 0xF7) {
          std::cout << "System Exclusive End: "
                    << ReadString(ifs, ReadValue(ifs)) << std::endl;
        }
      } else {
        std::cout << "Unrecognised Status Byte: " << (uint32_t)status
                  << std::endl;
      }
    }
  }
  for (MidiTrack &track : Tracks) {
    uint32_t absoluteTime = 0;

    std::vector<MidiNote> notesToProcessed;

    for (auto &event : track.Events) {
      absoluteTime += event.deltaTick;

      if (event.event == MidiEvent::EventType::NoteOn) {
        notesToProcessed.push_back(
            {event.key, event.velocity, absoluteTime, 0});
      }

      if (event.event == MidiEvent::EventType::NoteOff) {
        auto note =
            std::find_if(notesToProcessed.begin(),
                         notesToProcessed.end(),
                         [&](const MidiNote &n) { return n.key == event.key; });
        if (note != notesToProcessed.end()) {
          note->duration = absoluteTime - note->startTime;
          track.Notes.push_back(*note);
          track.minNote = std::min(track.minNote, note->key);
          track.maxNote = std::max(track.maxNote, note->key);
          notesToProcessed.erase(note);
        }
      }
    }
  }

  return true;
}

std::ostream &operator<<(std::ostream &os, const MidiFile &midi) {
  for (auto i : midi.Tracks)
    os << i;
  return os;
}
