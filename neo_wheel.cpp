#include "neo_wheel.h"

NeoWheel::NeoWheel(uint8_t pin, uint16_t numPixels, unsigned long duration) : Runnable(), NeoController(pin, numPixels) {
  index = 0;
  prevTimeMs = 0;
  updateIntervalMs = duration / steps;
}


void NeoWheel::run() {
  unsigned long currentTime = millis();
  unsigned long interval = currentTime - prevTimeMs;
  if( interval >= updateIntervalMs ) {
    setColor( wheel(index) );
    index = (index + 1) % steps;
    prevTimeMs = currentTime;
  }
}


void NeoWheel::setup() {
  NeoController::setup();
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
