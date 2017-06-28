#include "util.h"
#include "HARD.h"

#ifndef __LCD_H_
#define __LCD_H_

#define LCD_RS		BRD_LCD_RS
#define LCD_E		BRD_LCD_EN
#define LCD_DATA	BRD_DATA

void lcdInit();
void lcdSetBright(uint8_t value);
void lcdSetContrast(uint8_t value);
void lcdDraw(uint8_t x, uint8_t y, char c);
void lcdPrint(uint8_t x, uint8_t y, char* str);
void lcdClear();

#endif
