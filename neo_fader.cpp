#include "neo_fader.h"
#include "rgbw.h"

NeoFader::NeoFader(
  uint8_t pin, uint16_t numPixels, uint32_t color, uint32_t duration ) :
  NeoController(pin, numPixels),
  PeriodicEffect(duration, 255, Counter::Mode::RETURNING), color(color) { }


void NeoFader::applyChange() {
  setColor(fade());
}


uint32_t NeoFader::fade() {
  Counter i = PeriodicEffect::index;
  float p = i.percent();
  uint8_t r = p * RGBW::r(color);
  uint8_t g = p * RGBW::g(color);
  uint8_t b = p * RGBW::b(color);
  uint8_t w = p * RGBW::w(color);
  return RGBW::color(r,g,b,w);
}


void NeoFader::setup() { NeoController::begin(); }
