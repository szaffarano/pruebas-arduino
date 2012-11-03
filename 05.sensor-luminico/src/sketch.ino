#define LED 9
#define SENSOR 0

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  analogWrite(LED, analogRead(SENSOR));
  delay(20);
}
