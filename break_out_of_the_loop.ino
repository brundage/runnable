/*
 * Break Out of the loop() - Intermediate Arduino Programming
 * For the Brazos Valley Makers group
 * https://www.facebook.com/events/311230849280014/
 * Authors:
 *  - Dean Brundage https://github.com/brundage

     #     #  #######   #####    #####   #     #  
     ##   ##  #        #     #  #     #   #   #   
     # # # #  #        #        #          # #    
     #  #  #  #####     #####    #####      #     
     #     #  #              #        #     #     
     #     #  #        #     #  #     #     #     
     #     #  #######   #####    #####      #     
*/

const uint8_t LED_PIN = 9;
const uint8_t FADE_AMOUNT = 5;
uint8_t ledBrightness = 0;

enum ButtonStates {
  NOT_CLICKING = 0,
  CLICK_DOWN = 1,
  CLICK_WAITING = 2
};

const uint8_t  BUTTON_PIN = 7;
const uint8_t  BUTTON_SHORT_CLICK_MS = 250;
const uint16_t BUTTON_LONG_CLICK_MS = 750;
const uint16_t BUTTON_TIMEOUT_MS = 1000;
const uint8_t  BUTTON_DEBOUNCE_DELAY_MS = 50;

ButtonStates  buttonState = NOT_CLICKING;
unsigned long buttonDownMS = 0;
uint8_t buttonClicks = 0;


void setup() {
  pinMode( LED_PIN, OUTPUT );
  pinMode( BUTTON_PIN, INPUT_PULLUP );
}


void loop() {
  readButton();
  setLEDState();
  fadeLED();
  delay(30);
}


void setLEDState() {
  if( buttonState == CLICK_DOWN ) {
    ledBrightness = 255;
    analogWrite( LED_PIN, ledBrightness );
  }
}


void fadeLED() {
  if( ledBrightness >= 0 ) {
    ledBrightness = ledBrightness - FADE_AMOUNT;
    analogWrite( LED_PIN, ledBrightness );
  }
}

void readButton() {
  int state = digitalRead(BUTTON_PIN);

  if( buttonState == NOT_CLICKING && state == LOW ) {
    // Button pressed
    buttonDownMS = millis();
    buttonState = CLICK_DOWN;

  } else if( buttonState == CLICK_DOWN && state == HIGH ) {
    // Button released
    if( millis() - buttonDownMS < BUTTON_DEBOUNCE_DELAY_MS ) {
      // ignore

    } else if( millis() - buttonDownMS < BUTTON_SHORT_CLICK_MS ) {
      // Do short click thing
      buttonClicks++;
      buttonState = CLICK_WAITING;

    } else {
      // Do long click thing
      buttonState = NOT_CLICKING;
    }
  }
}
