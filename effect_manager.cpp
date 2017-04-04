#include "effect_manager.h"

EffectManager::EffectManager(
  NeoFader *fader, NeoWheel *wheel, uint8_t buttonPin) :
   Button(buttonPin), fader(fader), wheel(wheel), faderRunning(false) {
  click();  // Initialize so the fader runs first
}


void EffectManager::click() {
  faderRunning = ! faderRunning;
  if( faderRunning ) {
    wheel->stop();
    fader->start();
  } else {
    fader->stop();
    wheel->start();
  }
}
