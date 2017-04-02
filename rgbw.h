#ifndef RGBW_H
#define RGBW_H

class RGBW {

  public:
    static uint8_t  b(uint32_t c);
    static uint32_t color(uint8_t r, uint8_t g, uint8_t b);
    static uint32_t color(uint8_t r, uint8_t g, uint8_t b, uint8_t w);
    static uint8_t  g(uint32_t color);
    static uint8_t  r(uint32_t color);
    static uint32_t rotate(uint8_t deg, uint32_t c);
    static uint8_t  w(uint32_t color);
};

#endif
