#ifndef NEO_FADER_H
#define NEO_FADER_H

#include <Adafruit_NeoPixel.h>
#include "runnable.h"

class NeoFader : public Runnable {
  public:
    NeoFader(uint8_t pin, uint16_t numPixels, uint32_t color, unsigned long duration);
    void run();
    void setup();

  private:
    Adafruit_NeoPixel pixels;
    bool goingForward;
    unsigned long prevTimeMs, updateIntervalMs;
    uint8_t index;
    uint32_t color;
    const uint8_t steps = 255;

    uint32_t fade();
    void increment();
    void setColor(uint32_t c);

};

#endif
