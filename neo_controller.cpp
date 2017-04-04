#include "neo_controller.h"

NeoController::NeoController(
  uint8_t pin, uint32_t numPixels, uint8_t flags) :
  pixels(Adafruit_NeoPixel(numPixels, pin, flags)) { }


void NeoController::begin() {
  pixels.begin();
}


void NeoController::setColor(uint32_t color) {
  for( int i = 0; i < pixels.numPixels(); i++ ) {
    pixels.setPixelColor(i, color);
  }
  pixels.show();
}
