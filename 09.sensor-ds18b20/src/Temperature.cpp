#include "Temperature.h"

Temperature::Temperature(float temp) {
  celcius = temp;
}

Temperature::Temperature(String msg) {
  status = msg;
}

Temperature::Temperature(float temp, String msg) {
  celcius = temp;
  status = msg;
}

void Temperature::set(float value) {
  celcius = value;
}

boolean Temperature::valid() {
  return status == NULL;
}

String Temperature::get_status() {
  return status;
}

float Temperature::get() {
  return celcius;
}

Sensor::Sensor(uint8_t pid) {
  ds = new OneWire(pid);
  if (ds->search(sensor)) {
    sensorFound = true;
  }
}

Sensor::~Sensor() {
  delete ds;
}
Temperature Sensor::get_temperature() {
  byte present = 0;
  byte data[12];
  
  if (!sensorFound) {
    return Temperature("Sensor no encontrado");
  }

  if (OneWire::crc8(sensor, 7) != sensor[7]) {
      Temperature("CRC inválido!");
  }

  if (sensor[0] != 0x28) {
    return Temperature("Sólo DS18B20 soportado!");
  }
 
  ds->reset();
  ds->select(sensor);
  ds->write(0x44, 1);         // start conversion, with parasite power on at the end
  
  delay(1000);     // maybe 750ms is enough, maybe not
                   // we might do a ds.depower() here, but the reset will take care of it.
  
  present = ds->reset();
  ds->select(sensor);    
  ds->write(READ_SCRATCHPAD);         // Read Scratchpad

  for (byte i = 0; i < 9; i++) {           // we need 9 bytes
    data[i] = ds->read();
  }

  // convert the data to actual temperature
  unsigned int raw = (data[1] << 8) | data[0];
  byte cfg = (data[4] & 0x60);
  if (cfg == 0x00) {
    raw = raw << 3;  // 9 bit resolution, 93.75 ms
  } else if (cfg == 0x20) {
    raw = raw << 2; // 10 bit res, 187.5 ms
  } else if (cfg == 0x40) {
    raw = raw << 1; // 11 bit res, 375 ms
  }
  // default is 12 bit resolution, 750 ms conversion time

  return Temperature((float)raw / 16.0);
}

boolean Sensor::found() {
  return sensorFound;
}
