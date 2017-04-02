#ifndef LED_FLASHER_H
#define LED_FLASHER_H

#include <Arduino.h>


class LEDFlasher {
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
