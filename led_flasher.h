#ifndef LED_FLASHER_H
#define LED_FLASHER_H

#include <stdint.h>
#include "runnable.h"

class LEDFlasher : public Runnable {

  public:
    LEDFlasher( uint8_t ledPin, unsigned long onDuration, unsigned long offDuration );
    void run();
    void setup();

  private:
    bool isOn;
    uint8_t pin;
    unsigned long onIntervalMs, offIntervalMs, prevTimeMs;

    void toggle(bool state);
    void turnOff();
    void turnOn();
};

#endif
