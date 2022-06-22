#include "MKL43Z4.h"
#include "button_control.h"

int drvButtonsSW1Pressed(void) {
	if(GPIOD->PDIR & (1 << SW1_PIN)) {
		return 1;
	}
	return 0;
}

int drvButtonsSW2Pressed(void) {
	if(GPIOD->PDIR & (1 << SW2_PIN)) {
		return 1;
	}
	return 0;
}

void initButtons() {
	SW_01_PORT->PCR[SW1_PIN] |= (1 << 8) | (1 << 1) | (1 << 0);
	SW_02_PORT->PCR[SW2_PIN] |= (1 << 8) | (1 << 1) | (1 << 0);

	// Config Interrupt for the Buttons (Interrupt in Either Edge)
	SW_01_PORT->PCR[SW1_PIN] |= (0b1011U << 16);
	SW_02_PORT->PCR[SW2_PIN] |= (0b1011U << 16);
}
