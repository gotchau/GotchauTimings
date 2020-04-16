#ifndef GotchauTimings_h
#define GotchauTimings_h
#include <Arduino.h>

enum TimingType
{
    Millis = 0,
    Micros
};

enum TimingMode
{
    Period = 0,
    Frequency
};

class Timing
{
private:
    bool enabled = false;
    uint32_t now = 0;
    uint32_t last = 0;
    uint32_t period = 0;
    TimingType type = Millis;

public:
    Timing(uint32_t = 1000, TimingMode = Period, TimingType = Millis);
    void start();
    void stop();
    void setPeriod(uint32_t);
    void setFrequency(uint32_t);
    bool timeHasCome();
};
#endif