#include "neo_wheel.h"

NeoWheel::NeoWheel(uint8_t pin, uint16_t numPixels, unsigned long duration) {
  index = 0;
  pixels = Adafruit_NeoPixel(numPixels, pin, NEO_RGB+NEO_KHZ800);
  prevTimeMs = 0;
  updateIntervalMs = duration / steps;
}


void NeoWheel::run() {
  unsigned long currentTime = millis();
  unsigned long interval = currentTime - prevTimeMs;
  if( interval >= updateIntervalMs ) {
    for( int i = 0; i < pixels.numPixels(); i++ ) {
      pixels.setPixelColor( i, wheel(index) );
    }
    pixels.show();
    index = (index + 1) % steps;
    prevTimeMs = currentTime;
  }
}


void NeoWheel::setup() {
  pixels.begin();
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
