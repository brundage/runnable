#include "effect_manager.h"

EffectManager::EffectManager(
  NeoFader *fader, NeoWheel *wheel, uint8_t buttonPin) :
   Button(buttonPin), fader(fader), wheel(wheel), faderRunning(true) {
  click();  // Initialize so the fader runs first
}


void EffectManager::click() {
  if( faderRunning ) {
    wheel->start();
    fader->stop();
  } else {
    fader->start();
    wheel->stop();
  }
  faderRunning = ! faderRunning;
}
