#include <LiquidCrystal.h>

#define RS 	4
#define ENABLED	5
#define D4 	6
#define D5 	7
#define D6 	8
#define D7 	9

#define RED	10
#define GREEN	11
#define PUSH	A2

#define DEBOUNCE_DELAY	50

LiquidCrystal *lcd;
int lastState = LOW;
int pushState;
long lastDebounceTime = 0;

void setup() {
   pinMode(RED, OUTPUT);
   pinMode(GREEN, OUTPUT);
   pinMode(PUSH, INPUT);

   lcd = new LiquidCrystal(RS, ENABLED, D4, D5, D6, D7);
   lcd->begin(16, 2);
   lcd->print("Hola mundo");
   lcd->setCursor(0, 1);
}

void loop() {
   int reading = analogRead(PUSH);
   pushState = reading;
/*
   if (reading != lastState) {
      lastDebounceTime = millis();
   }

   long time = millis() - lastDebounceTime;
   if (time > DEBOUNCE_DELAY) {
      if (reading != pushState) {
         pushState = reading;
      }
   }

*/
   if (pushState > 20) {
      digitalWrite(RED, HIGH);
      digitalWrite(GREEN, LOW);
      lcd->setCursor(0, 1);
      lcd->print(pushState);
   } else {
      digitalWrite(RED, LOW);
      digitalWrite(GREEN, HIGH);
      lcd->setCursor(0, 1);
      //lcd->print("               "); 
      //lcd->print(pushState);
   }
   lastState = reading;
}
