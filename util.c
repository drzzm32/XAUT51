#include "util.h"

void delay(uint16_t time) {
	uint8_t i, j; uint16_t t;
	i = 2; j = 199; t = time;
	do {
		do {
			while (--j);
		} while (--i);
	} while (--t);
}

void delayMicroseconds(uint16_t time) {
	uint16_t t;
	t = time;
	while (--t);
}
