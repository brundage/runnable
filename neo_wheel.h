#ifndef NEO_WHEEL_H
#define NEO_WHEEL_H

#include <Adafruit_NeoPixel.h>

class NeoWheel {
  public:
    NeoWheel(uint8_t pin, uint16_t numPixels, unsigned long duration);
    void run();
    void setup();

  private:
    Adafruit_NeoPixel pixels;
    unsigned long prevTimeMs, updateIntervalMs;
    uint8_t index;
    const uint8_t steps = 255;

    uint32_t wheel(uint8_t pos);

};

#endif
