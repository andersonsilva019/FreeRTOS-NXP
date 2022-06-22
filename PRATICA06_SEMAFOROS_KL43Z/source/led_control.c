#include "MKL43Z4.h"
#include "led_control.h"

void drvLedsSet(int num, int status) {
	if(num == LED_GREEN) {
		if(status == ON) {
			lowLedGreen();
		} else {
			highLedGreen();
		}
	} else {
		if(status == ON) {
			lowLedRed();
		} else {
			highLedRed();
		}
	}
}

void highLedGreen(){
	LED_GREEN_PORT->PCR[LED_GREEN] |= (1 << 8);
	LED_GREEN_GPIO->PDDR |= (1 << LED_GREEN);
	LED_GREEN_GPIO->PCOR |= (1 << LED_GREEN);
}

void lowLedGreen(){
	LED_GREEN_PORT->PCR[LED_GREEN] |= (1 << 8);
	LED_GREEN_GPIO->PDDR |= (1 << LED_GREEN);
	LED_GREEN_GPIO->PSOR |= (1 << LED_GREEN);
}

void highLedRed(){
	LED_RED_PORT->PCR[LED_RED] |= (1 << 8);
	LED_RED_GPIO->PDDR |= (1 << LED_RED);
	LED_RED_GPIO->PCOR |= (1 << LED_RED);
}

void lowLedRed(){
	LED_RED_PORT->PCR[LED_RED] |= (1 << 8);
	LED_RED_GPIO->PDDR |= (1 << LED_RED);
	LED_RED_GPIO->PSOR |= (1 << LED_RED);
}
