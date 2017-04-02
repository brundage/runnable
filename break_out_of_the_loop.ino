/*
 * Break Out of the loop() - Intermediate Arduino Programming
 * For the Brazos Valley Makers group
 * https://www.facebook.com/events/311230849280014/
 * Authors:
 *  - Dean Brundage https://github.com/brundage

######   #     #  #######  #######  #######  #     #
#     #  #     #     #        #     #     #  ##    #
#     #  #     #     #        #     #     #  # #   #
######   #     #     #        #     #     #  #  #  #
#     #  #     #     #        #     #     #  #   # #
#     #  #     #     #        #     #     #  #    ##
######    #####      #        #     #######  #     #

*/

#include "button.h"
#include "led_flasher.h"
#include "neo_fader.h"
#include "neo_wheel.h"

const LEDFlasher led(7, 150, 2000);
const NeoFader   neo(8, 1, 0xFF00FF, 8000);
const Button  button(10);

void setup() {
  button.setup();
  led.setup();
  neo.setup();
}


void loop() {
  button.run();
//  led.run();
  neo.run();
}
