
/**
 * Title: Light Level
 * Description: Uses the LEDs to show the Light Sensor reading
 */

#include "alpha.h"


void setup() {
  // put your setup code here, to run once:
  pinMode(AL_LED_RED, OUTPUT);
  pinMode(AL_LED_YELLOW, OUTPUT);
  pinMode(AL_LED_GREEN, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  int light = analogRead(AL_LDR);

  if (light > 700) {
    digitalWrite(AL_LED_RED, HIGH);
    digitalWrite(AL_LED_YELLOW, LOW);
    digitalWrite(AL_LED_GREEN, LOW);
  } else if (light > 300) {
    digitalWrite(AL_LED_RED, LOW);
    digitalWrite(AL_LED_YELLOW, HIGH);
    digitalWrite(AL_LED_GREEN, LOW);
  } else {
    digitalWrite(AL_LED_RED, LOW);
    digitalWrite(AL_LED_YELLOW, LOW);
    digitalWrite(AL_LED_GREEN, HIGH);
  }

}
