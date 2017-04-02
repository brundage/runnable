#include "led_flasher.h"
#include <Arduino.h>

LEDFlasher::LEDFlasher( uint8_t ledPin, unsigned long onDuration, unsigned long offDuration ) : Runnable(), pin(ledPin), onIntervalMs(onDuration), offIntervalMs(offDuration) {
   prevTimeMs = 0;
   isOn = false;
}


void LEDFlasher::run() {
  unsigned long currentTime = millis();
  unsigned long interval = currentTime - prevTimeMs;

  if( isOn && interval >= onIntervalMs ) {
    turnOff();
    prevTimeMs = currentTime;
  } else if( ! isOn && interval >= offIntervalMs ) {
    turnOn();
    prevTimeMs = currentTime;
  }
}


void LEDFlasher::setup() {
  pinMode( pin, OUTPUT );
}


void LEDFlasher::toggle(bool state) {
  digitalWrite( pin, state ? HIGH : LOW );
  isOn = state;
}


void LEDFlasher::turnOff() {
  toggle(false);
}


void LEDFlasher::turnOn() {
  toggle(true);
}
