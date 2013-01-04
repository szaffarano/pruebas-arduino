#include <IRremote.h>
#include "YK001.h"
#include "Key.h"

// Constantes del receptor
int RECV_PIN = 11;

// Constantes del 74HC595
int LATCH_PIN = 4;
int CLK_PIN = 3;
int DATA_PIN = 2;

// Clase que representa al receptor, de la librería IRremote
IRrecv *irrecv;

// variable para los resultados de la lectura
decode_results results;

void setup() {
  Serial.begin(9600);
 
  irrecv = new IRrecv (RECV_PIN);
  irrecv->enableIRIn();

  // inicializo pines para el 595
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(CLK_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);

  // dejo "apagado" el display de 7 segmentos
  digitalWrite(LATCH_PIN, LOW);
  shiftOut(DATA_PIN, CLK_PIN, MSBFIRST, 128);
  digitalWrite(LATCH_PIN, HIGH);
}

void loop() {
  if (irrecv->decode(&results)) {
    for (int i = 0; i<21; i++) {
        if (codes[i].getCode() == results.value) {
            digitalWrite(LATCH_PIN, LOW);
            shiftOut(DATA_PIN, CLK_PIN, MSBFIRST, get_digit(codes[i].getCode()));
            digitalWrite(LATCH_PIN, HIGH);
            Serial.println(codes[i].getName());
            break;
        }
    }
    irrecv->resume(); 
  }
}

int get_digit(unsigned long code) {
   int digit = 0;
   switch (results.value)  {
      case 0xFFA25D:
        digit=73;
        break;
      case 0xFF6897:
        digit=63;
        break;
      case 0xFF30CF:
        digit=6;
        break;
      case 0xFF18E7:
        digit=91;
        break;
      case 0xFF7A85:
        digit=79;
        break;
      case 0xFF10EF:
        digit=102;
        break;
      case 0xFF38C7:
        digit=109;
        break;
      case 0xFF5AA5:
        digit=125;
        break;
      case 0xFF42BD:
        digit=7;
        break;
      case 0xFF4AB5:
        digit=127;
        break;
      case 0xFF52AD:
        digit=111;
        break;
   }
   return digit;
}
