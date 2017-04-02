/*
 * Break Out of the loop() - Intermediate Arduino Programming
 * For the Brazos Valley Makers group
 * https://www.facebook.com/events/311230849280014/
 * Authors:
 *  - Dean Brundage https://github.com/brundage

   ____________ 
  < Neo Pixels >
   ------------ 
          \   ^__^
           \  (@@)\_______
              (__)\       )\/\
                  ||----w |
                  ||     ||
*/

#include "led_flasher.h"
#include "neo_fader.h"
#include "neo_wheel.h"

const LEDFlasher led = LEDFlasher(7, 150, 2000);
const NeoFader   neo = NeoFader(8, 1, 0xFF00FF, 8000);


void setup() {
  Serial.begin(9600);
  led.setup();
  neo.setup();
}


void loop() {
  led.run();
  neo.run();
}
