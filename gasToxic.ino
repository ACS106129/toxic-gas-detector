#include <stdarg.h>
#include "music.h"

const float NOTE_FOUR_DURATION = 187.5;
const float WAIT_DURATION = NOTE_FOUR_DURATION * 0.2f;
const float AVC_VALUE = 5.f / 1023;
const int BRIGHT_CEILING = 255;
const int RIGHT_BUZZER_DPIN = 3;
const int LEFT_BUZZER_DPIN = 10;
const int RIGHT_RED_DPIN = 5;
const int GREENLED_DPIN = 6;
const int LEFT_RED_DPIN = 9;
const int MQ2_DPIN = 12;
const int MQ3_DPIN = 2;
const auto MQ2_APIN = A0;
const auto MQ3_APIN = A1;

// milliseconds, 0 ~ 1 brightness range, number of led, pins
void flashDelay(const int delayMS, const float startBrightness, const float endBrightness, const int LEDNumbers, ...)
{
    if (LEDNumbers == 0 || delayMS < 0)
        return;
    const int end = (int)(endBrightness * BRIGHT_CEILING);
    va_list ap;
    va_start(ap, LEDNumbers);
    int *ledPins = (int *)malloc(sizeof(int) * LEDNumbers);
    for (int i = 0; i < LEDNumbers; ++i)
        ledPins[i] = va_arg(ap, int);
    // process flash
    int tempDelay = delayMS;
    if (delayMS > 30)
    {
        const int fadeAmount = (int)((30.f / delayMS) * (endBrightness - startBrightness) * BRIGHT_CEILING);
        int start = startBrightness * BRIGHT_CEILING;
        for (int i = 0; i < LEDNumbers; ++i)
            digitalWrite(ledPins[i], HIGH);
        do
        {
            for (int i = 0; i < LEDNumbers; ++i)
                analogWrite(ledPins[i], start);
            delay(30);
            start += fadeAmount;
            tempDelay -= 30;
        } while (tempDelay > 30);
    }
    // remain of delay
    delay(tempDelay);
    for (int i = 0; i < LEDNumbers; ++i)
        analogWrite(ledPins[i], end);
    // finalize
    va_end(ap);
    free(ledPins);
}

int *getSubList(const uint16_t *list, const int start, const int size)
{
    int *subList = (int *)malloc(sizeof(int) * size);
    for (int i = 0; i < size; ++i)
        subList[i] = pgm_read_word(&list[i + start]);
    return subList;
}

void determineVoltage(const float v, const float limit, const Song song)
{
    if (v < limit)
        return;
    if (song == Song::CuffinDance)
        play(cuda::MELODY, cuda::MELODY_SIZE, cuda::BLOCK_SIZE);
}

void play(const uint16_t *melody, const int size, const int blockSize)
{
    for (int i = 0; i < size; i += blockSize)
    {
        int *temp = getSubList(melody, i, blockSize);
        bool ledSwitch = true;
        for (int j = 0; j < blockSize; j += 2, ledSwitch = !ledSwitch)
        {
            if (temp[j] == NOTE_END)
                break;
            const int duration = NOTE_FOUR_DURATION * temp[j] / 4;
            const float delayDuration = (duration + WAIT_DURATION) / 2;
            tone(LEFT_BUZZER_DPIN, temp[j + 1], duration);
            if (ledSwitch)
            {
                flashDelay(delayDuration, 0, 1, 1, GREENLED_DPIN);
                flashDelay(delayDuration, 1, 0, 1, GREENLED_DPIN);
            }
            else
            {
                flashDelay(delayDuration, 0, 0.5f, 2, LEFT_RED_DPIN, RIGHT_RED_DPIN);
                flashDelay(delayDuration, 0.5f, 0, 2, LEFT_RED_DPIN, RIGHT_RED_DPIN);
            }
            noTone(LEFT_BUZZER_DPIN);
        }
        free(temp);
    }
}

void setup()
{
    Serial.begin(9600);
    pinMode(LEFT_BUZZER_DPIN, OUTPUT);
    pinMode(RIGHT_BUZZER_DPIN, OUTPUT);
    pinMode(LEFT_RED_DPIN, OUTPUT);
    pinMode(RIGHT_RED_DPIN, OUTPUT);
    pinMode(GREENLED_DPIN, OUTPUT);
}

void loop()
{
    const int MQ3AValue = analogRead(MQ3_APIN);
    const int MQ2AValue = analogRead(MQ2_APIN);
    // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
    const float MQ3Voltage = MQ3AValue * AVC_VALUE;
    const float MQ2Voltage = MQ2AValue * AVC_VALUE;
    determineVoltage(MQ3Voltage, 3.66f, Song::CuffinDance);
    determineVoltage(MQ2Voltage, 1.9f, Song::CuffinDance);
    Serial.println(MQ3Voltage + String("MQ3"));
    Serial.println(MQ2Voltage + String("MQ2"));
    delay(1000);
}