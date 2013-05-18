#include <LCDDisplay.h>
#include <MenuEntry.h>

LCDDisplay::LCDDisplay(uint8_t rs, uint8_t en, uint8_t d4, uint8_t d5, 
			uint8_t d6, uint8_t d7, uint8_t cols, uint8_t rows): Display(cols, rows) {
	
	this->lcd = new LiquidCrystal(rs, en, d4, d5, d6, d7);
	this->lcd->begin(cols, rows);
}

void LCDDisplay::clear() {
	lcd->clear();
}

void LCDDisplay::setCursor(uint8_t col, uint8_t row) {
	lcd->setCursor(col, row);
}

size_t LCDDisplay::print(const char str[]) {
	return lcd->print(str);
}

size_t LCDDisplay::print(const char ch) {
	return lcd->print(ch);
}

LCDDisplay::~LCDDisplay() {
}

