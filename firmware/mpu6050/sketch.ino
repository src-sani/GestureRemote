#include <Wire.h>

#define MPU_ADDR 0x68

#define LED_UP     PA0
#define LED_DOWN   PA1
#define LED_LEFT   PA2
#define LED_RIGHT  PA3

float lastX = 0;
float lastY = 0;

bool firstReading = true;
bool gestureLocked = false;

const float CHANGE_THRESHOLD = 0.3;
const float RESET_THRESHOLD = 0.15;

// --------------------------------
// SEND COMMAND
// --------------------------------

void sendCommand(const char* command) {
  Serial1.println(command);
}

// --------------------------------
// SETUP
// --------------------------------

void setup() {

  pinMode(LED_UP, OUTPUT);
  pinMode(LED_DOWN, OUTPUT);
  pinMode(LED_LEFT, OUTPUT);
  pinMode(LED_RIGHT, OUTPUT);

  allOff();

  // USART1
  // PA9  = TX
  // PA10 = RX
  Serial1.begin(115200);

  Wire.begin();
  Wire.setClock(100000);

  // Wake up MPU6050
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x6B);
  Wire.write(0x00);
  Wire.endTransmission();

  delay(100);

  Serial1.println("Gesture Remote Ready");
}

// --------------------------------
// TURN ALL LEDs OFF
// --------------------------------

void allOff() {

  digitalWrite(LED_UP, LOW);
  digitalWrite(LED_DOWN, LOW);
  digitalWrite(LED_LEFT, LOW);
  digitalWrite(LED_RIGHT, LOW);
}

// --------------------------------
// FLASH LED
// --------------------------------

void flashLED(int pin) {

  digitalWrite(pin, HIGH);
  delay(250);
  digitalWrite(pin, LOW);
}

// --------------------------------
// READ MPU6050
// --------------------------------

bool readMPU(float &x, float &y, float &z) {

  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x3B);

  if (Wire.endTransmission() != 0) {
    return false;
  }

  delay(2);

  if (Wire.requestFrom(MPU_ADDR, 6) != 6) {
    return false;
  }

  int16_t ax = (Wire.read() << 8) | Wire.read();
  int16_t ay = (Wire.read() << 8) | Wire.read();
  int16_t az = (Wire.read() << 8) | Wire.read();

  // ±2g sensitivity
  x = ax / 16384.0;
  y = ay / 16384.0;
  z = az / 16384.0;

  return true;
}

// --------------------------------
// MAIN LOOP
// --------------------------------

void loop() {

  float x, y, z;

  if (!readMPU(x, y, z)) {
    return;
  }

  // First reading establishes reference
  if (firstReading) {

    lastX = x;
    lastY = y;

    firstReading = false;

    return;
  }

  float deltaX = x - lastX;
  float deltaY = y - lastY;

  // --------------------------------
  // DETECT ONE GESTURE
  // --------------------------------

  if (!gestureLocked) {

    // RIGHT
    if (deltaX > CHANGE_THRESHOLD) {

      flashLED(LED_RIGHT);
      sendCommand("RIGHT");

      gestureLocked = true;
    }

    // LEFT
    else if (deltaX < -CHANGE_THRESHOLD) {

      flashLED(LED_LEFT);
      sendCommand("LEFT");

      gestureLocked = true;
    }

    // UP
    else if (deltaY > CHANGE_THRESHOLD) {

      flashLED(LED_UP);
      sendCommand("UP");

      gestureLocked = true;
    }

    // DOWN
    else if (deltaY < -CHANGE_THRESHOLD) {

      flashLED(LED_DOWN);
      sendCommand("DOWN");

      gestureLocked = true;
    }
  }

  // --------------------------------
  // RE-ARM AFTER MOVEMENT SETTLES
  // --------------------------------

  if (gestureLocked &&
      abs(deltaX) < RESET_THRESHOLD &&
      abs(deltaY) < RESET_THRESHOLD) {

    gestureLocked = false;
  }

  lastX = x;
  lastY = y;

  delay(50);
}