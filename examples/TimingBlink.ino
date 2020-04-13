#include <GotchauTimings.h>

Timing ledBlink(1000, Period, Millis);
bool ledState = false;

void setup()
{

}

void loop()
{
    if(ledBlink.timeHasCome())
    {
        digitalWrite(LED_BUILTIN, ledState);
        ledState = !ledState;
    }
}