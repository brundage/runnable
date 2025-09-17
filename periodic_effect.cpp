#include <Arduino.h>
#include "periodic_effect.h"

PeriodicEffect::PeriodicEffect(
  uint32_t durationMs, uint32_t periods, Counter::Mode mode ) :
  Runnable(), index(periods, mode), intervalMs(durationMs/periods),
  periods(periods) { }


void PeriodicEffect::run() {
  uint32_t currTimeMs = millis();
  if( (currTimeMs - prevTimeMs) > intervalMs ) {
    applyChange();
    prevTimeMs = currTimeMs;
    index.increment();
  }
}