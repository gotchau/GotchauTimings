#include <Arduino.h>
#include <GotchauTimings.h>

Timing::Timing(uint32_t time, TimingMode mode, TimingType type)
{
    switch (mode)
    {
    case Period:
        setPeriod(time);
        break;
    case Frequency:
        setFrequency(time);
        break;
    }
}

void Timing::setPeriod(uint32_t p)
{
    period = p;
}

void Timing::setFrequency(uint32_t fr)
{
    switch (type)
    {
    case Millis:
        period = 1000 / fr;
        break;
    case Micros:
        period = 1000000 / fr;
        break;
    }
}

bool Timing::timeHasCome()
{
    switch (type)
    {
    case Millis:
        now = millis();
        break;
    case Micros:
        now = micros();
        break;
    }

    if (now - last >= period)
    {
        last = now;
        return true;
    }
    else
        return false;
}