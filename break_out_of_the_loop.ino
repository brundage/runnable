/*
 * Break Out of the loop() - Intermediate Arduino Programming
 * For the Brazos Valley Makers group
 * https://www.facebook.com/events/311230849280014/
 * Authors:
 *  - Dean Brundage https://github.com/brundage

   ________________
  ( In e-f-f-e-c-t )
   ----------------
          \   ^__^
           \  (oo)\_______
              (__)\       )\/\
                  ||----w |
                  ||     ||

*/

#include "led_flasher.h"
#include "neo_fader.h"
#include "neo_wheel.h"
#include "effect_manager.h"


const LEDFlasher led(7, 150, 2000);
const NeoFader fader = NeoFader(8, 1, 0xBF18A8, 1500);
const NeoWheel wheel = NeoWheel(8, 1, 5000);
const EffectManager manager( &fader, &wheel, 10 );


void setup() {
  Runnable::setupAll();
}


void loop() {
  Runnable::runAll();
}
