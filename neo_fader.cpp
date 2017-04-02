#include "neo_fader.h"
#include "rgbw.h"

NeoFader::NeoFader(uint8_t pin, uint16_t numPixels, uint32_t color, unsigned long duration) : Runnable(), color(color) {
  goingForward = true;
  index = 128;
  pixels = Adafruit_NeoPixel(numPixels, pin, NEO_RGB+NEO_KHZ800);
  prevTimeMs = 0;
  updateIntervalMs = duration / steps;
}


void NeoFader::run() {
  unsigned long currentTime = millis();
  unsigned long interval = currentTime - prevTimeMs;
  if( interval >= updateIntervalMs ) {
    setColor(fade());
    increment();
    prevTimeMs = currentTime;
  }
}


uint32_t NeoFader::fade() {
  float percent = (float) index / (float) steps; 
  uint8_t r = percent * RGBW::r(color);
  uint8_t g = percent * RGBW::g(color);
  uint8_t b = percent * RGBW::b(color);
  uint8_t w = percent * RGBW::w(color);
  return RGBW::color(r,g,b,w);
}


void NeoFader::increment() {
  if( goingForward ) {
    index++;
    if( index >= steps ) {
      index = steps - 1;
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


void NeoFader::setColor(uint32_t c) {
  for( int i = 0; i < pixels.numPixels(); i++ ) {
    pixels.setPixelColor(i, c);
  }
  pixels.show();
}


void NeoFader::setup() {
//  pixels.setBrightness(16);
  pixels.begin();
  setColor(color);
}
