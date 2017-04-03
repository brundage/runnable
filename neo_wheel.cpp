#include "neo_wheel.h"

NeoWheel::NeoWheel(uint8_t pin, uint16_t numPixels, unsigned long duration) : NeoController(pin, numPixels), PeriodicEffect(duration, 255) {
}


void NeoWheel::applyChange() {
  uint8_t i = PeriodicEffect::index.getIndex();
  setColor( wheel(i) );
}


void NeoWheel::setup() {
  NeoController::begin();
}


uint32_t NeoWheel::wheel(uint8_t pos) {
  pos = 255 - pos;
  if( pos < 85 ) {
    return Adafruit_NeoPixel::Color( 255-3*pos, 0, 3*pos );
  } else if( pos < 170 ) {
    pos -= 85;
    return Adafruit_NeoPixel::Color( 0, 3*pos, 255-3*pos );
  } else {
    pos -= 170;
    return Adafruit_NeoPixel::Color( 3*pos, 255 - 3*pos, 0);
  }
}
