#ifndef COUNTER_H
#define COUNTER_H

#include <stdint.h>


class Counter {
  public:
    enum Mode { RESETTING, RETURNING };
    Counter(uint32_t limit, Counter::Mode mode = RESETTING, uint32_t index = 0);

    uint32_t getIndex();
    void increment();
    float percent();

  private:
    uint32_t index;
    bool goingForward;
    const uint32_t limit;
    const Counter::Mode mode;

    void incrementReturning();
    void incrementResetting();

};

#endif
