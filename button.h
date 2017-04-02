#ifndef BUTTON_H
#define BUTTON_H

class Button {
  public:
    Button(uint8_t pin);
    void run();
    void setup();


  private:
    const uint8_t pin;
    const uint8_t debounceDelayMs = 50;
    uint32_t buttonDownMs;
    int state;

};

#endif
