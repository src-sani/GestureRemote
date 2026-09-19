#define LED_UP     PA0
#define LED_DOWN   PA1
#define LED_LEFT   PA2
#define LED_RIGHT  PA3

void blinkLED(int pin) {
  digitalWrite(pin, HIGH);
  delay(100);
  digitalWrite(pin, LOW);
}

void setup() {
  pinMode(LED_UP, OUTPUT);
  pinMode(LED_DOWN, OUTPUT);
  pinMode(LED_LEFT, OUTPUT);
  pinMode(LED_RIGHT, OUTPUT);

  Serial1.begin(9600);
}

void loop() {

  // RIGHT
  Serial1.println("RIGHT");
  blinkLED(LED_RIGHT);
  delay(2000);

  // LEFT
  Serial1.println("LEFT");
  blinkLED(LED_LEFT);
  delay(2000);

  // UP
  Serial1.println("UP");
  blinkLED(LED_UP);
  delay(2000);

  // DOWN
  Serial1.println("DOWN");
  blinkLED(LED_DOWN);
  delay(2000);
}