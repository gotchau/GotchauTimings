#ifndef GotchauTimings_h
#define GotchauTimings_h
#include <Arduino.h>

class TimingMicros
{
private:
    int32_t lastMicros = 0;
    int32_t periodMicros = 0;
public:
    TimingMicros(int32_t, int8_t);
    TimingMicros();
    void SetPeriod(int32_t);
    void SetFrequency(int32_t);
    bool timeHasCome();    
};

class TimingMillis
{
private:
    int32_t lastMillis = 0;
    int32_t periodMillis = 0;
public:
    TimingMillis(int32_t, int8_t);
    TimingMillis();
    void SetPeriod(int32_t);
    void SetFrequency(int32_t);
    bool timeHasCome();    
};
#endif