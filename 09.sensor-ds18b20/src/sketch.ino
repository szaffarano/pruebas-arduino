#include "Temperature.h"
#include <LiquidCrystal.h>

#define SENSOR_PID 3
#define GRADOS (uint8_t)0

Sensor *sensor;
LiquidCrystal *lcd;

byte grados[8] = {
  0b1000,
  0b10100,
  0b1000,
  0b0,
  0b0,
  0b0,
  0b0
};

void setup(void) {
  sensor = new Sensor(SENSOR_PID);
  lcd = new LiquidCrystal(7,8,9,10,11,12);

  // creo el caracter º
  lcd->createChar(GRADOS, grados);

  // seteo 16x2 (16 columnas, 2 filas)
  lcd->begin(16, 2);

  lcd->print("Temperatura");
}

void loop(void) {
  lcd->setCursor(0, 1);

  if (!sensor->found()) {
    lcd->print("No Sensor");
    delay(2000);
    delete sensor;
    sensor = new Sensor(SENSOR_PID);
    return;
  }

  Temperature temp = sensor->get_temperature().get();
  if (!temp.valid()) {
    lcd->print(temp.get_status());
  } else {
    lcd->print(temp.get());
    lcd->write(GRADOS);
    lcd->print("C");
  }

}
