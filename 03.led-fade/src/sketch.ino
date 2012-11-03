#define LED 9
#define SPEED 20

int i = 0;
void setup() {
   pinMode(LED, OUTPUT);
}

void loop() {
   fade(0, 255, 1);
   fade(255, 0, -1);
}

void fade(int from, int to, int increment) {
   for (int i = from; i != to; i += increment) {
      analogWrite(LED, i);
      delay(SPEED);
   }
}
