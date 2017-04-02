/*
 * Break Out of the loop() - Intermediate Arduino Programming
 * For the Brazos Valley Makers group
 * https://www.facebook.com/events/311230849280014/
 * Authors:
 *  - Dean Brundage https://github.com/brundage

   _____________
  < LED flasher >
   ------------- 
          \   ^__^
           \  (oo)\_______
              (__)\       )\/\
                  ||----w |
                  ||     ||
*/

#include "led_flasher.h"

const LEDFlasher flasher = LEDFlasher(7, 150, 2000);


void setup() {
  flasher.setup();  
}


void loop() {
  flasher.run();
}
