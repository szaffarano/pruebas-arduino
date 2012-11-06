#include <LiquidCrystal.h>

LiquidCrystal lcd(7,8,9,10,11,12);

byte grados[8] = {
  0b1000,
  0b10100,
  0b1000,
  0b0,
  0b0,
  0b0,
  0b0
};

void setup() {
  // creo el caracter º
  lcd.createChar(0, grados);

  // seteo 16x2 (16 columnas, 2 filas)
  lcd.begin(16, 2);

  lcd.print("Control de Clima");
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):

  lcd.setCursor(0, 1);
  // print the number of seconds since reset:

  lcd.print(millis()/1000);
  lcd.write((uint8_t)0);
  lcd.print("C");
  lcd.print(" - 100%");
  lcd.print(" hum");
}
