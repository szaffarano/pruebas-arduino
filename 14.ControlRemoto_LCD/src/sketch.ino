#include <Wire.h>
#include <LiquidCrystal_SR.h>
#include <IRremote.h>
#include "YK001.h"
#include "Key.h"

// Constantes del receptor
int RECV_PIN = 11;

// Clase que representa al LCD.  parametros: clock, data, enable
LiquidCrystal_SR lcd(3,1,4);

// Clase que representa al receptor, de la librería IRremote
IRrecv *irrecv;

// variable para los resultados de la lectura
decode_results results;

void setup() {
  irrecv = new IRrecv (RECV_PIN);
  irrecv->enableIRIn();

  lcd.begin (16,2);
  lcd.home ();
  lcd.print("Leyendo...");
}

void loop(){

  if (irrecv->decode(&results)) {
    for (int i = 0; i<21; i++) {
        if (codes[i].getCode() == results.value) {
            lcd.setCursor(0, 1);
            lcd.print("Tecla:          "); 
            lcd.setCursor(7, 1);
            lcd.print(codes[i].getName());
            break;
        }
    }
    irrecv->resume(); 
  }
}
