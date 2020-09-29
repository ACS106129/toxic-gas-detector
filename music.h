#pragma once
#include "pitches.h"

enum Song
{
    CuffinDance
};

// about notes, followed by a duration and a pitch
// prefix note durations: 4 = quarter note, 8 = eighth note, etc.:
// suffix note pitches
namespace cuda
{
    static const int BLOCK_SIZE = 128;

    static const uint16_t MELODY[] PROGMEM = {
        4, NOTE_G4, 4, NOTE_G4, 4, NOTE_G4, 4, NOTE_G4, 4, NOTE_G4, 4, NOTE_G4, 4, NOTE_G4, 4, NOTE_G4,
        4, NOTE_G4, 4, NOTE_G4, 4, NOTE_G4, 4, NOTE_G4, 4, NOTE_G4, 4, NOTE_G4, 4, NOTE_G4, 4, NOTE_G4,
        4, NOTE_AS4, 4, NOTE_AS4, 4, NOTE_AS4, 4, NOTE_AS4, 4, NOTE_AS4, 4, NOTE_AS4, 4, NOTE_AS4, 4, NOTE_AS4,
        4, NOTE_AS4, 4, NOTE_AS4, 4, NOTE_AS4, 4, NOTE_AS4, 4, NOTE_AS4, 4, NOTE_AS4, 4, NOTE_AS4, 4, NOTE_AS4,
        4, NOTE_AS4, 4, NOTE_AS4, 4, NOTE_AS4, 4, NOTE_AS4, 4, NOTE_D5, 4, NOTE_D5, 4, NOTE_D5, 4, NOTE_D5,
        4, NOTE_C5, 4, NOTE_C5, 4, NOTE_C5, 4, NOTE_C5, 4, NOTE_F5, 4, NOTE_F5, 4, NOTE_F5, 4, NOTE_F5,
        4, NOTE_G5, 4, NOTE_G5, 4, NOTE_G5, 4, NOTE_G5, 4, NOTE_G5, 4, NOTE_G5, 4, NOTE_G5, 4, NOTE_G5,
        4, NOTE_G5, 4, NOTE_G5, 4, NOTE_G5, 4, NOTE_G5, 4, NOTE_C5, 4, NOTE_AS4, 4, NOTE_A4, 4, NOTE_F4,
        4, NOTE_G4, 4, REST, 4, NOTE_G4, 4, NOTE_D5, 4, NOTE_C5, 4, REST, 4, NOTE_AS4, 4, REST,
        4, NOTE_A4, 4, REST, 4, NOTE_A4, 4, NOTE_A4, 4, NOTE_C5, 4, REST, 4, NOTE_AS4, 4, NOTE_A4,
        4, NOTE_G4, 4, REST, 4, NOTE_G4, 4, NOTE_AS5, 4, NOTE_A5, 4, NOTE_AS5, 4, NOTE_A5, 4, NOTE_AS5,
        4, NOTE_G4, 4, REST, 4, NOTE_G4, 4, NOTE_AS5, 4, NOTE_A5, 4, NOTE_AS5, 4, NOTE_A5, 4, NOTE_AS5,
        4, NOTE_G4, 4, REST, 4, NOTE_G4, 4, NOTE_D5, 4, NOTE_C5, 4, REST, 4, NOTE_AS4, 4, REST,
        4, NOTE_A4, 4, REST, 4, NOTE_A4, 4, NOTE_A4, 4, NOTE_C5, 4, REST, 4, NOTE_AS4, 4, NOTE_A4,
        4, NOTE_G4, 4, REST, 4, NOTE_G4, 4, NOTE_AS5, 4, NOTE_A5, 4, NOTE_AS5, 4, NOTE_A5, 4, NOTE_AS5,
        4, NOTE_G4, 4, REST, 4, NOTE_G4, 4, NOTE_AS5, 4, NOTE_A5, 4, NOTE_AS5, 4, NOTE_A5, 4, NOTE_AS5,
        4, NOTE_G4, 4, REST, 4, NOTE_G4, 4, NOTE_D5, 4, NOTE_C5, 4, REST, 4, NOTE_AS4, 4, REST,
        4, NOTE_A4, 4, REST, 4, NOTE_A4, 4, NOTE_A4, 4, NOTE_C5, 4, REST, 4, NOTE_AS4, 4, NOTE_A4,
        4, NOTE_G4, 4, REST, 4, NOTE_G4, 4, NOTE_AS5, 4, NOTE_A5, 4, NOTE_AS5, 4, NOTE_A5, 4, NOTE_AS5,
        4, NOTE_G4, 4, REST, 4, NOTE_G4, 4, NOTE_AS5, 4, NOTE_A5, 4, NOTE_AS5, 4, NOTE_A5, 4, NOTE_AS5,
        4, NOTE_AS4, 4, NOTE_AS4, 4, NOTE_AS4, 4, NOTE_AS4, 4, NOTE_D5, 4, NOTE_D5, 4, NOTE_D5, 4, NOTE_D5,
        4, NOTE_C5, 4, NOTE_C5, 4, NOTE_C5, 4, NOTE_C5, 4, NOTE_F5, 4, NOTE_F5, 4, NOTE_F5, 4, NOTE_F5,
        4, NOTE_G5, 4, NOTE_G5, 4, NOTE_G5, 4, NOTE_G5, 4, NOTE_G5, 4, NOTE_G5, 4, NOTE_G5, 4, NOTE_G5,
        4, NOTE_G5, 4, NOTE_G5, 4, NOTE_G5, 4, NOTE_G5, 4, NOTE_C5, 4, NOTE_AS4, 4, NOTE_A4, 4, NOTE_F4,
        4, NOTE_G4, 4, REST, 4, NOTE_G4, 4, NOTE_D5, 4, NOTE_C5, 4, REST, 4, NOTE_AS4, 4, REST,
        4, NOTE_A4, 4, REST, 4, NOTE_A4, 4, NOTE_A4, 4, NOTE_C5, 4, REST, 4, NOTE_AS4, 4, NOTE_A4,
        4, NOTE_G4, 4, REST, 4, NOTE_G4, 4, NOTE_AS4, 4, NOTE_A5, 4, NOTE_AS5, 4, NOTE_A5, 4, NOTE_AS5,
        4, NOTE_G4, 4, REST, 4, NOTE_G4, 4, NOTE_AS4, 4, NOTE_A5, 4, NOTE_AS5, 4, NOTE_A5, 4, NOTE_AS5,
        4, NOTE_G4, 4, REST, 4, NOTE_G4, 4, NOTE_D5, 4, NOTE_C5, 4, REST, 4, NOTE_AS4, 4, REST,
        4, NOTE_A4, 4, REST, 4, NOTE_A4, 4, NOTE_A4, 4, NOTE_C5, 4, REST, 4, NOTE_AS4, 4, NOTE_A4,
        4, NOTE_G4, 4, REST, 4, NOTE_G4, 4, NOTE_AS4, 4, NOTE_A5, 4, NOTE_AS5, 4, NOTE_A5, 4, NOTE_AS5,
        4, NOTE_G4, 4, REST, 4, NOTE_G4, 4, NOTE_AS4, 4, NOTE_A5, 4, NOTE_AS5, 4, NOTE_A5, 4, NOTE_AS5,
        4, NOTE_G4, 4, REST, 4, NOTE_G4, 4, NOTE_D5, 4, NOTE_C5, 4, REST, 4, NOTE_AS4, 4, REST,
        4, NOTE_A4, 4, REST, 4, NOTE_A4, 4, NOTE_A4, 4, NOTE_C5, 4, REST, 4, NOTE_AS4, 4, NOTE_A4,
        4, NOTE_G4, 4, REST, 4, NOTE_G4, 4, NOTE_AS4, 4, NOTE_A5, 4, NOTE_AS5, 4, NOTE_A5, 4, NOTE_AS5,
        4, NOTE_G4, 4, REST, 4, NOTE_G4, 4, NOTE_AS4, 4, NOTE_A5, 4, NOTE_AS5, 4, NOTE_A5, 4, NOTE_AS5,
        4, NOTE_AS4, 4, NOTE_AS4, 4, NOTE_AS4, 4, NOTE_AS4, 4, NOTE_D5, 4, NOTE_D5, 4, NOTE_D5, 4, NOTE_D5,
        4, NOTE_C5, 4, NOTE_C5, 4, NOTE_C5, 4, NOTE_C5, 4, NOTE_F5, 4, NOTE_F5, 4, NOTE_F5, 4, NOTE_F5,
        4, NOTE_G5, 4, NOTE_G5, 4, NOTE_G5, 4, NOTE_G5, 4, NOTE_G5, 4, NOTE_G5, 4, NOTE_G5, 4, NOTE_G5,
        4, NOTE_G5, 4, NOTE_G5, 4, NOTE_G5, 4, NOTE_G5, 4, NOTE_G5, 4, NOTE_G5, 4, NOTE_G5, 4, NOTE_G5,
        32, NOTE_G5, 32, NOTE_G5, 32, NOTE_G5, 32, NOTE_G5, 4, NOTE_G4, 4, REST, 4, NOTE_G4, 4, NOTE_D5,
        4, NOTE_C5, 4, REST, 4, NOTE_AS4, 4, REST, 4, NOTE_G4, 4, REST, 4, NOTE_G4, 4, NOTE_D5,
        4, NOTE_C5, 4, REST, 4, NOTE_AS4, 4, REST, 4, NOTE_G4, 4, REST, 4, NOTE_G4, 4, NOTE_D5,
        4, NOTE_C5, 4, REST, 4, NOTE_AS4, 4, REST, 4, NOTE_G4, 4, REST, 4, NOTE_G4, 4, NOTE_D5,
        4, NOTE_C5, 4, REST, 4, NOTE_AS4, 4, REST, 4, NOTE_G4, 4, REST, 4, NOTE_G4, 4, NOTE_D5,
        4, NOTE_C5, 4, REST, 4, NOTE_AS4, 4, REST, 4, NOTE_G4, 4, REST, 4, NOTE_G4, 4, NOTE_D5,
        4, NOTE_C5, 4, REST, 4, NOTE_AS4, 4, REST, 4, NOTE_G4, 4, REST, 4, NOTE_G4, 4, NOTE_D5,
        4, NOTE_C5, 4, REST, 4, NOTE_AS4, 4, REST, 4, NOTE_G4, 4, REST, 4, NOTE_G4, 4, NOTE_AS5,
        4, NOTE_A5, 4, NOTE_AS5, 4, NOTE_A5, 4, NOTE_AS5, 32, NOTE_AS4, 32, NOTE_AS4, 4, NOTE_AS4, 4, NOTE_AS4,
        4, NOTE_AS4, 4, NOTE_AS4, 4, NOTE_AS4, 4, NOTE_AS4, 4, NOTE_AS4, 4, NOTE_AS4, 4, NOTE_AS4, 4, NOTE_AS4,
        4, NOTE_AS4, 4, NOTE_AS4, 4, NOTE_AS4, 4, NOTE_AS4, 4, NOTE_AS4, 4, NOTE_AS4, 4, NOTE_AS4, 4, NOTE_AS4,
        4, NOTE_AS4, 4, NOTE_AS4, 4, NOTE_D5, 4, NOTE_D5, 4, NOTE_D5, 4, NOTE_D5, 4, NOTE_C5, 4, NOTE_C5,
        4, NOTE_C5, 4, NOTE_C5, 4, NOTE_F5, 4, NOTE_F5, 4, NOTE_F5, 4, NOTE_F5, 4, NOTE_G5, 4, NOTE_G5,
        4, NOTE_G5, 4, NOTE_G5, 4, NOTE_G5, 4, NOTE_G5, 4, NOTE_G5, 4, NOTE_G5, 4, NOTE_G5, 4, NOTE_G5,
        4, NOTE_G5, 4, NOTE_G5, 4, NOTE_C5, 4, NOTE_AS4, 4, NOTE_A4, 4, NOTE_F4, 4, NOTE_G4, 4, REST,
        4, NOTE_G4, 4, NOTE_D5, 4, NOTE_C5, 4, REST, 4, NOTE_AS4, 4, REST, 4, NOTE_A4, 4, REST,
        4, NOTE_A4, 4, NOTE_A4, 4, NOTE_C5, 4, REST, 4, NOTE_AS4, 4, NOTE_A4, 4, NOTE_G4, 4, REST,
        4, NOTE_G4, 4, NOTE_AS5, 4, NOTE_A5, 4, NOTE_AS5, 4, NOTE_A5, 4, NOTE_AS5, 4, NOTE_G4, 4, REST,
        4, NOTE_G4, 4, NOTE_AS5, 4, NOTE_A5, 4, NOTE_AS5, 4, NOTE_A5, 4, NOTE_AS5, 4, NOTE_G4, 4, REST,
        4, NOTE_G4, 4, NOTE_D5, 4, NOTE_C5, 4, REST, 4, NOTE_AS4, 4, REST, 4, NOTE_A4, 4, REST,
        4, NOTE_A4, 4, NOTE_A4, 4, NOTE_C5, 4, REST, 4, NOTE_AS4, 4, NOTE_A4, 4, NOTE_G4, 4, REST,
        4, NOTE_G4, 4, NOTE_AS5, 4, NOTE_A5, 4, NOTE_AS5, 4, NOTE_A5, 4, NOTE_AS5, 4, NOTE_G4, 4, REST,
        4, NOTE_G4, 4, NOTE_AS5, 4, NOTE_A5, 4, NOTE_AS5, 4, NOTE_G4, 4, REST, 4, NOTE_G4, 4, NOTE_D5,
        4, NOTE_C5, 4, REST, 4, NOTE_AS4, 4, REST, 4, NOTE_A4, 4, REST, 4, NOTE_A4, 4, NOTE_A4,
        4, NOTE_C5, 4, REST, 4, NOTE_AS4, 4, NOTE_A4, 4, NOTE_G4, 4, REST, 4, NOTE_G4, 4, NOTE_AS5,
        4, NOTE_A5, 4, NOTE_AS5, 4, NOTE_A5, 4, NOTE_AS5, 4, NOTE_G4, 4, REST, 4, NOTE_G4, 4, NOTE_AS5,
        4, NOTE_A5, 4, NOTE_AS5, 4, NOTE_A5, 4, NOTE_AS5, 4, NOTE_AS4, 4, NOTE_AS4, 4, NOTE_AS4, 4, NOTE_AS4,
        4, NOTE_D5, 4, NOTE_D5, 4, NOTE_D5, 4, NOTE_D5, 4, NOTE_C5, 4, NOTE_C5, 4, NOTE_C5, 4, NOTE_C5,
        4, NOTE_F5, 4, NOTE_F5, 4, NOTE_F5, 4, NOTE_F5, 4, NOTE_G5, 4, NOTE_G5, 4, NOTE_G5, 4, NOTE_G5,
        4, NOTE_G5, 4, NOTE_G5, 4, NOTE_G5, 4, NOTE_G5, 4, NOTE_G5, 4, NOTE_G5, 4, NOTE_G5, 4, NOTE_G5,
        4, NOTE_G5, 4, NOTE_G5, 4, NOTE_G5, 4, NOTE_G5, 4, NOTE_G5, NOTE_END};

    static const uint16_t MELODY_SIZE = sizeof(MELODY) / sizeof(MELODY[0]);
} // namespace cuda
