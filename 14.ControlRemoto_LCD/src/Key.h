#include <Arduino.h>

#ifndef KEY_H
#define KEY_H

class Key {
    unsigned long code;
    String name;
  public:
    Key(String name, unsigned long code);
    unsigned long getCode();
    String getName();
};

#endif
