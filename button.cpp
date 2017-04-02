#include <Arduino.h>
#include "button.h"

Button::Button(uint8_t pin) : Runnable(), pin(pin) {
  buttonDownMs = 0;
  state = HIGH;
}


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
      digitalWrite(7, ! digitalRead(7) );
    }
  }
}


void Button::setup() {
  pinMode(pin, INPUT);
}
