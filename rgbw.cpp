#include <stdint.h>
#include "rgbw.h"

static uint8_t RGBW::b(uint32_t c) {
  return (uint8_t)c;
}


static uint32_t RGBW::color(uint8_t r, uint8_t g, uint8_t b) {
  return ((uint32_t)r << 16) | ((uint32_t)g << 8) | b;
}


static uint32_t RGBW::color(uint8_t r, uint8_t g, uint8_t b,  uint8_t w) {
  return ((uint32_t)w << 24) | ((uint32_t)r << 16) | ((uint32_t)g << 8) | b;
}


static uint8_t RGBW::g(uint32_t c) {
  return (uint8_t)(c >> 8);
}


static uint8_t RGBW::r(uint32_t c) {
  return (uint8_t)(c >> 16);
}


static uint32_t RGBW::rotate(uint8_t deg, uint32_t c=0) {
  uint8_t pos, r, g, b;
  deg = 255 - deg;
  if( deg < 85 ) {
    r = 256 - 3* deg;
    g = 0;
    b = 3 * deg;
  } else if( deg < 170 ) {
    r = 0;
    g = 3 * deg;
    b = 255 - 3 * deg;
  } else {
    deg -= 170;
    r = 3 * deg;
    g = 255 - 3 * deg;
    b = 0;
  }
  return color(r,g,b);
}


static uint8_t RGBW::w(uint32_t c) {
  return (uint8_t)(c >> 24);
}
