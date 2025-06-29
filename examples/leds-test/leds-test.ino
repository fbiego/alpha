/**
 * Title: LEDs Test
 * Description: Cycles through the Red, Yellow and Green onboard LEDS one at a time at 1 second interval
 */

#include "alpha.h"

void setup() {
  pinMode(AL_LED_RED, OUTPUT);
  pinMode(AL_LED_YELLOW, OUTPUT);
  pinMode(AL_LED_GREEN, OUTPUT);
  
}

void loop() {
  digitalWrite(AL_LED_RED, HIGH);
  digitalWrite(AL_LED_YELLOW, LOW);
  digitalWrite(AL_LED_GREEN, LOW);
  delay(1000);
  digitalWrite(AL_LED_RED, LOW);
  digitalWrite(AL_LED_YELLOW, HIGH);
  digitalWrite(AL_LED_GREEN, LOW);
  delay(1000);
  digitalWrite(AL_LED_RED, LOW);
  digitalWrite(AL_LED_YELLOW, LOW);
  digitalWrite(AL_LED_GREEN, HIGH);
  delay(1000);   
}
