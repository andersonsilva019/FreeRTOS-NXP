#ifndef BUTTON_CONTROL_H_
#define BUTTON_CONTROL_H_

#define SW_01_PORT PORTD
#define SW_02_PORT PORTD

#define SW1_PIN			4		// D4
#define SW2_PIN 		2		// D2

extern int drvButtonsSW1Pressed(void);

extern int drvButtonsSW2Pressed(void);

extern void initButtons();

#endif /* BUTTON_CONTROL_H_ */
