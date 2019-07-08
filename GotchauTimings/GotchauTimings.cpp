#include <Arduino.h>
#include <GotchauTimings.h>

TimingMicros::TimingMicros(int32_t t, int8_t mode)
{
    if (mode == 0)
        TimingMicros::setPeriod(t);
    if (mode == 1)
        TimingMicros::setFrequency(t);
}

TimingMicros::TimingMicros()
{
}

void TimingMicros::setPeriod(int32_t p)
{
    periodMicros = p;
}

void TimingMicros::setFrequency(int32_t fr)
{
    periodMicros = 1000000 / fr;
}

bool TimingMicros::timeHasCome()
{
    int32_t nowMicros = micros();
    if (nowMicros - lastMicros >= periodMicros)
    {
        lastMicros = nowMicros;
        return true;
    }
    else
        return false;
}

TimingMillis::TimingMillis(int32_t t, int8_t mode)
{
    if (mode == 0)
        TimingMillis::setPeriod(t);
    if (mode == 1)
        TimingMillis::setFrequency(t);
}

TimingMillis::TimingMillis()
{
}

void TimingMillis::setPeriod(int32_t p)
{
    periodMillis = p;
}

void TimingMillis::setFrequency(int32_t fr)
{
    periodMillis = 1000 / fr;
}

bool TimingMillis::timeHasCome()
{
    int32_t nowMillis = millis();
    if (nowMillis - lastMillis >= periodMillis)
    {
        lastMillis = nowMillis;
        return true;
    }
    else
        return false;
}