#ifndef EFFECT_MANAGER_H
#define EFFECT_MANAGER_H

#include "button.h"
#include "neo_fader.h"
#include "neo_wheel.h"

class EffectManager : public Button {
  public:
    EffectManager(NeoFader *, NeoWheel *, uint8_t buttonPin);

  private:
    NeoFader *fader;
    NeoWheel *wheel;
    bool faderRunning;

    void click();

};

#endif
