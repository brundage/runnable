#ifndef NEO_WHEEL_H
#define NEO_WHEEL_H

#include "neo_controller.h"
#include "periodic_effect.h"

class NeoWheel : public NeoController, public PeriodicEffect {
  public:
    NeoWheel(uint8_t pin, uint16_t numPixels, unsigned long duration);
    void setup();

  private:
    void applyChange();
    uint32_t wheel(uint8_t pos);

};

#endif
