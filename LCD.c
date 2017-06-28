#include "LCD.h"

void writeByte(uint8_t value, uint8_t rs) {
	delay(1);
	LCD_RS = rs;
	delay(1);
	delay(1);
	LCD_E = 0;
	LCD_DATA = value;
	delay(1);
	LCD_E = 1;
	delay(1);
	LCD_E = 0;
}

void writeCmd(uint8_t value) { writeByte(value, 0); }

void writeData(uint8_t value) { writeByte(value, 1); }

void lcdInit() {	
	writeCmd(0x38);
	writeCmd(0x08);
	writeCmd(0x06);
	writeCmd(0x01);
	writeCmd(0x0C);
	writeCmd(0x80);
}

void lcdDraw(uint8_t x, uint8_t y, char c) {
	writeCmd(0x80 + ((y > 0) ? 0x40 : 0) + x);
	writeData(c);
}

void lcdPrint(uint8_t x, uint8_t y, char* str) {
	uint8_t i; uint8_t tx = x, ty = y;
	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] == '\n') {
			tx = x;
			ty = 1 - ty;
		} else {
			lcdDraw(tx + i, ty, str[i]);
		}
	}
}

void lcdClear() {
	writeCmd(0x01);
	delay(1);
}
