/**
 * Title: Light-Controlled Theremin
 * Description: Light-Controlled where the pitch is controlled by the amount of light hitting the LDR, and the tempo of the beeps is controlled by Potentiometer A1. The Green LED lights up when a note is playing
 */

// define pin variables
#define AL_BUZZER 9
#define AL_LED_GREEN 11
#define AL_LDR A0
#define AL_POT_A1 A1
#define AL_POT_A2 A2


void setup() {
  pinMode(AL_LED_GREEN, OUTPUT);
  pinMode(AL_BUZZER, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  
  int ldrValue = analogRead(AL_LDR);  // Read the value of LDR 
  int noteDelayTempoValue = analogRead(AL_POT_A1); // Read the value of Potentiometer A1
  int noteDurationTempoValue = analogRead(AL_POT_A2); // Read the value of Potentiometer A2

  // Map LDR reading to a musical frequency range
  int frequency = map(ldrValue, 0, 1023, 100, 2000); // Darker = lower pitch

  // print the frequency on serial monitor 
  Serial.print("Frequency(Hz): "); 
  Serial.println(frequency);

  // Map potentiometerA1 reading to a delay between notes 
  int noteDelay = map(noteDelayTempoValue, 0, 1023, 50, 1000);
  // Map potentiometer A2 reading to a note duration between notes  in ms 
  int noteDuration = map(noteDurationTempoValue, 0, 1023, 100, 2000);

  // print the Note Delay on serial monitor 
  Serial.print("Note Delay(ms): ");
  Serial.println(noteDelay);

  // print the Note Duation on serial monitor 
  Serial.print("Note Duation(ms): ");
  Serial.println(noteDuration);

  digitalWrite(AL_LED_GREEN, HIGH);
  tone(AL_BUZZER, frequency, noteDuration); // Play each note for based on the note duration
  delay(noteDelay);
  digitalWrite(AL_LED_GREEN, LOW);
  delay(noteDuration);

}
