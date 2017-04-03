#ifndef PERIODIC_EFFECT_H
#define PERIODIC_EFFECT_H

#include "counter.h"
#include "runnable.h"

class PeriodicEffect : public Runnable {

  public:
    PeriodicEffect( uint32_t durationMs, uint32_t periods, Counter::Mode mode = Counter::Mode::RESETTING );

    const Counter index;

  private:
    const uint32_t intervalMs, periods;
    uint32_t prevTimeMs;

    virtual void applyChange() = 0;
    void run();
    virtual void setup() = 0;
};

#endif
