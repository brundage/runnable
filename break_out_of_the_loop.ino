/*
 * Break Out of the loop() - Intermediate Arduino Programming
 * For the Brazos Valley Makers group
 * https://www.facebook.com/events/311230849280014/
 * Authors:
 *  - Dean Brundage https://github.com/brundage

   _________ 
  < Run cow >
   --------- 
          \   ^__^
           \  (oo)\_______
              (__)\       )\/\
                  ||----w |
                  ||     ||

*/

#include "button.h"
#include "led_flasher.h"
#include "neo_fader.h"
#include "neo_wheel.h"


const LEDFlasher led(7, 150, 2000);
//const NeoFader   neo(8, 1, 0xBF18A8, 1500);
const NeoWheel   neo(8, 1, 1500);
const Button  button(10);

void setup() {
  Serial.begin(19200);
  Runnable::setupAll();
}


void loop() {
  Runnable::runAll();
}
