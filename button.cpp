#include "button.h"
#include <Arduino.h>

Button::Button(uint8_t pin) :
   Runnable(), buttonDownMs(0), pin(pin), state(HIGH) { }


void Button::run() {
  int prevState = state;
  state = digitalRead(pin);
  if( prevState == HIGH && state == LOW ) {
    // button pressed
    buttonDownMs = millis();

  } else if(prevState == LOW && state == HIGH) {
    // button released
    if( millis() - buttonDownMs < debounceDelayMs ) {
      // ignore debounce
    } else {
      // press
      click();
    }
  }
}


void Button::setup() { pinMode(pin, INPUT); }
