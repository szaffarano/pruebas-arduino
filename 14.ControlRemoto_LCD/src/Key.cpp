#include "Key.h"

Key::Key(String name, unsigned long code) {
    this->code = code;
    this->name = name;
}

unsigned long Key::getCode() {
    return code;
}

String Key::getName() {
    return name;
}

