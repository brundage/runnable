#ifndef NEO_FADER_H
#define NEO_FADER_H

#include "neo_controller.h"
#include "periodic_effect.h"

class NeoFader : public NeoController, public PeriodicEffect {
  public:
    NeoFader(uint8_t pin, uint16_t numPixels, uint32_t color, uint32_t duration);
    void setup();

  private:
    uint32_t color;

    void applyChange();
    uint32_t fade();

};

#endif
