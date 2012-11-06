// Example testing sketch for various DHT humidity/temperature sensors
// Written by ladyada, public domain

#include "DHT.h"
#include <LiquidCrystal.h>

#define DHTPIN 2     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)

byte grados[8] = {
  0b1000,
  0b10100,
  0b1000,
  0b11100,
  0b0,
  0b0,
  0b0
};

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(7,8,9,10,11,12);


void setup() {

  // creo el caracter º
  lcd.createChar(0, grados);

  // inicializo pantalla lcd: seteo 16x2 (16 columnas, 2 filas)
  lcd.begin(16, 2);

  // inicializo sensor dht22
  dht.begin();

  lcd.print("Control de Clima");
  lcd.setCursor(0, 1);
  lcd.print("Bienvenido!");
  delay(1500);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Inicializando");
  lcd.setCursor(0, 1);
  lcd.print("sensores");
  delay(500);
  lcd.print(".");
  delay(500);
  lcd.print(".");
  delay(500);
  lcd.print(".");
  delay(500);
  lcd.clear();
}

void loop() {

  // posiciono el cursor en la posición 0 de la segunda línea
  lcd.setCursor(0, 0);

  // leo datos del sensor, se demora 250 ms hasta 2 segundos
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // chequeo si la lectura fue correcta o erronea
  if (isnan(t) || isnan(h)) {
    lcd.print("Error de lectura");
  } else {
    lcd.print("Temp.: ");
    lcd.print(t);
    lcd.write((uint8_t)0);
    lcd.println("C  ");

    lcd.setCursor(0, 1);
    lcd.print("Humedad: ");
    lcd.print(h);
    lcd.write(" %");
  }

}
