#ifndef LED_CONTROL_H_
#define LED_CONTROL_H_

#define LED_RED 		31
#define LED_GREEN 		5
#define ON 				1
#define OFF 			0

#define LED_RED_PORT PORTE
#define LED_GREEN_PORT PORTD

#define LED_RED_GPIO GPIOE
#define LED_GREEN_GPIO GPIOD

extern void drvLedsSet(int num, int status);
extern void highLedGreen();
extern void lowLedGreen();
extern void highLedRed();
extern void lowLedRed();

typedef struct {
	unsigned int num;
	unsigned int status;
} LedInfo;

#endif /* LED_CONTROL_H_ */
