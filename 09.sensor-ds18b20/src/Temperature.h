#include "OneWire.h"

#define READ_SCRATCHPAD 0xBE

class Temperature {
    float celcius;
    String status;
  public:
    Temperature(float celcius);
    Temperature(String status);
    Temperature(float celcius, String status);
    void set(float value);
    String get_status();
    boolean valid();
    float get();
};

class Sensor {
    OneWire *ds;
    byte sensor[8];
    boolean sensorFound = false;
  public:
    Sensor(uint8_t pid);
    Temperature get_temperature(); 
    boolean found();
    ~Sensor();
};
