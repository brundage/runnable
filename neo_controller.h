#ifndef NEO_CONTROLLER_H
#define NEO_CONTROLLER_H

#include <Adafruit_NeoPixel.h>

class NeoController {
  public:
    NeoController(uint8_t pin, uint32_t numPixels, uint8_t flags = NEO_RGB + NEO_KHZ800);

    void setColor(uint32_t c);
    void setColor(uint8_t r, uint8_t g, uint8_t b, uint8_t w);

    void setup();

  private:
    const Adafruit_NeoPixel pixels;

};

#endif
