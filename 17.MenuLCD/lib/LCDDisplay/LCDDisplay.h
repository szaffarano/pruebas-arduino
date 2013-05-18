#include <Display.h>
#include <LiquidCrystal.h>

#ifndef LCD_DISPLAY_H_
#define LCD_DISPLAY_H_

class LCDDisplay: public Display {
	LiquidCrystal* lcd;
public:
	LCDDisplay(uint8_t rs, uint8_t en, uint8_t d4, uint8_t d5, 
			uint8_t d6, uint8_t d7, uint8_t rows, uint8_t characters);
	void clear();
	void setCursor(uint8_t col, uint8_t row);
	void createChar(uint8_t, uint8_t[]);
	size_t print(const char[]);
	size_t print(const char);
	~LCDDisplay();
};

#endif // LCD DISPLAY
