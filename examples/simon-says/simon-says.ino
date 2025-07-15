/**
 * Title: Simon Says
 * Description: A memory game using green/red LEDs and buttons. User must repeat the light/sound sequence.
 */

#include "alpha.h"

// Pin definitions using Alpha board macros
#define GREEN_LED AL_LED_GREEN     // 11
#define RED_LED AL_LED_RED         // 13
#define BUZZER AL_BUZZER           // 9

#define BUTTON_GREEN AL_BUTTON_A5  // A5
#define BUTTON_RED AL_BUTTON_A4    // A4

// Game configuration
const int sequenceLength = 3;
int sequence[sequenceLength];
int currentLevel = 1;

void setup() {
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  pinMode(BUTTON_GREEN, INPUT_PULLUP);
  pinMode(BUTTON_RED, INPUT_PULLUP);

  Serial.begin(9600);
  randomSeed(analogRead(AL_LDR));  // Use LDR as noise source for randomness

  generateSequence();
  introSequence();
}

void loop() {
  // Play the current sequence
  for (int i = 0; i < currentLevel; i++) {
    playLED(sequence[i]);
    delay(300);
  }

  // Get player input and check
  for (int i = 0; i < currentLevel; i++) {
    int playerInput = getPlayerInput();
    if (playerInput != sequence[i]) {
      failSequence();
      currentLevel = 1;
      delay(1000);
      return;
    }
  }

  successBeep();
  currentLevel++;

  if (currentLevel > sequenceLength) {
    winSequence();
    currentLevel = 1;
  }

  delay(1000);  // Pause before next round
}

void generateSequence() {
  for (int i = 0; i < sequenceLength; i++) {
    sequence[i] = random(0, 2);  // 0 = green, 1 = red
  }
}

void playLED(int color) {
  int ledPin = (color == 0) ? GREEN_LED : RED_LED;
  int toneFreq = (color == 0) ? 1000 : 500;

  digitalWrite(ledPin, HIGH);
  tone(BUZZER, toneFreq);
  delay(300);
  digitalWrite(ledPin, LOW);
  noTone(BUZZER);
}

int getPlayerInput() {
  while (true) {
    if (digitalRead(BUTTON_GREEN) == HIGH) {
      waitRelease(BUTTON_GREEN);
      playLED(0);  // feedback
      return 0;
    }
    if (digitalRead(BUTTON_RED) == HIGH) {
      waitRelease(BUTTON_RED);
      playLED(1);  // feedback
      return 1;
    }
  }
}

void waitRelease(int pin) {
  while (digitalRead(pin) == HIGH) {
    // Wait for button release
  }
  delay(100);  // Debounce
}

void introSequence() {
  for (int i = 0; i < 2; i++) {
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, HIGH);
    tone(BUZZER, 800);
    delay(200);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, LOW);
    noTone(BUZZER);
    delay(200);
  }
}

void failSequence() {
  Serial.println("❌ WRONG SEQUENCE");
  for (int i = 0; i < 3; i++) {
    digitalWrite(RED_LED, HIGH);
    tone(BUZZER, 300);
    delay(150);
    digitalWrite(RED_LED, LOW);
    noTone(BUZZER);
    delay(150);
  }
}

void successBeep() {
  tone(BUZZER, 1200);
  delay(150);
  noTone(BUZZER);
  delay(100);
  tone(BUZZER, 1500);
  delay(150);
  noTone(BUZZER);
}

void winSequence() {
  for (int i = 0; i < 5; i++) {
    digitalWrite(GREEN_LED, HIGH);
    tone(BUZZER, 1000);
    delay(100);
    digitalWrite(GREEN_LED, LOW);
    noTone(BUZZER);
    delay(100);
  }
  Serial.println("🏆 YOU WIN!");
}
