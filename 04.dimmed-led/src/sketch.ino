#define BUTTON 7
#define LED 9

#define LED_ON 1
#define LED_OFF 0

int val = LOW;
int old_val = LOW;

int state = LED_OFF;

int brightness = 128;
unsigned long startTime = 0;


void setup() {
   pinMode(BUTTON, INPUT);
   pinMode(LED, OUTPUT);
}

void loop() {
   val = digitalRead(BUTTON);

   if (val == HIGH && old_val == LOW) {
      state = LED_ON - state;
      startTime = millis();
      delay(10);
   }

    if ((val == HIGH) && (old_val == HIGH)) {
       if (state == LED_ON && (millis() - startTime) > 500) {
          brightness++; 
          delay(10); 

          if (brightness > 255) {
             brightness = 0;
          }
       }
   }

   old_val = val;

   if (state == LED_ON) {
     analogWrite(LED, brightness);
   } else {
     analogWrite(LED, 0);
   }
   delay(10);
}
