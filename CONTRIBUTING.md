# 📚 Sketch Naming & Contribution Guide

## 📂 Project Structure

- Sketches must be placed under the `examples` folder:
```
alpha
 └─ examples
     └─ sketch-name
         └─ sketch-name.ino
```

- **Naming Rules:**
  - Sketch folder and file names must be the same.
  - Do **not** include "alpha", "alpha board", or similar in the sketch name.
  - Use **short, simple names:**
    - Maximum **3 words**
    - Words separated by hyphens
    - All **lowercase letters**

---

## 🛠️ Sketch Structure

Follow this order when writing sketches:
```cpp
/**
 * Title: Sketch Title
 * Description: Brief description of what the sketch does.
 */

#include "alpha.h"
// other includes (don't add Arduino.h)

// defines

// Library objects (e.g., Servo myServo;)
// Global variables

// Function declarations (if needed)

void setup() {
  ...
}

void loop() {
  ...
}

// Other functions
```

- Always use the provided `#define` pin mappings for hardware components.

```cpp
#define AL_BUZZER 9
#define AL_IR_TX 4
#define AL_SERVO_D5 5 // external
#define AL_SERVO_D6 6 // external
#define AL_IR_RX 7
#define AL_LED_GREEN 11
#define AL_LED_YELLOW 12
#define AL_LED_RED 13

#define AL_LDR A0
#define AL_POT_A1 A1
#define AL_POT_A2 A2
#define AL_NTC A3
#define AL_BUTTON_A4 A4
#define AL_BUTTON_A5 A5
```

- Format your code using Arduino IDE's Auto Format (Ctrl + T).

## ✅ Contribution Rules
- Create a separate pull request (PR) for each sketch.
- Each PR should contain only one example sketch addition.