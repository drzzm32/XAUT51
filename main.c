#include "LCD.h"

void init() {
	BRD_LAT_LED_LE = 0;
	BRD_LAT_DDS_LE = 0;
	BRD_LAT_DDP_LE = 0;
	BRD_DATA = 0x00;
	BRD_LAT_LED_LE = 1;
	BRD_LAT_DDS_LE = 1;
	BRD_LAT_DDP_LE = 1;
	BRD_DATA = 0xFF;
	
	BRD_LCD_RS = 1;
	BRD_LCD_EN = 1;
}

void main() {
	init();
	
	lcdInit();
	lcdClear();
	
	lcdPrint(0, 0, "Hello World!");
	lcdPrint(0, 1, "Hello Gensokyo!");
	
	while (1);
}
