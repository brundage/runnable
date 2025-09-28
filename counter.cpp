#include "counter.h"

Counter::Counter(
  uint32_t limit, Counter::Mode mode, uint32_t index ) :
  goingForward(true), index(index), limit(limit), mode(mode) { }


uint32_t Counter::getIndex() {
  return index;
}


uint32_t Counter::increment() {
  switch( mode ) {
    case RESETTING : incrementResetting();
                     break;
    case RETURNING : incrementReturning();
                     break;
  }
  return index;
}


void Counter::incrementResetting() {
  index = (index + 1) % limit;
}


void Counter::incrementReturning() {
  if( goingForward ) {
    index++;
    if( index >= limit ) {
      index = limit - 1;
      goingForward = false;
    }
  } else {
    index--;
    if( index <= 0 ) {
      index = 1;
      goingForward = true;
    }
  }
}


float Counter::percent() {
  return (float) index / (float) limit;
}
