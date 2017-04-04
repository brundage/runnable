#include <Arduino.h>
#include "led_flasher.h"

LEDFlasher::LEDFlasher(
   uint8_t ledPin, unsigned long onDuration, unsigned long offDuration ) :
   Runnable(), isOn(false), pin(ledPin), prevTimeMs(0),
   onIntervalMs(onDuration), offIntervalMs(offDuration) { }


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
Serial.println("LEDFlasher setup");
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
