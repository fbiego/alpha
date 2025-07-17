/**
 * Title: Pot LED Chaser
 * Description: Turns on red, yellow, or green LED based on potentiometer position.
 */

#include "alpha.h"

void setup()
{
 pinMode(AL_LED_RED, OUTPUT);
 pinMode(AL_LED_YELLOW, OUTPUT);
 pinMode(AL_LED_GREEN, OUTPUT);
}

void loop()
{
 int potVal = analogRead(AL_POT_A1); // 0–1023

 digitalWrite(AL_LED_RED, LOW);
 digitalWrite(AL_LED_YELLOW, LOW);
 digitalWrite(AL_LED_GREEN, LOW);

 if (potVal < 341)
 {
  digitalWrite(AL_LED_GREEN, HIGH);
 }
 else if (potVal < 682)
 {
  digitalWrite(AL_LED_YELLOW, HIGH);
 }
 else
 {
  digitalWrite(AL_LED_RED, HIGH);
 }
}
