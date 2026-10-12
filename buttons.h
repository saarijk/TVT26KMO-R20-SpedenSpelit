#ifndef BUTTONS_H
#define BUTTONS_H
#include <arduino.h>
#include <avr/io.h>
#include <avr/interrupt.h>

extern volatile int buttonNumber;

void initializeButtons(void);
//int readButton();

#endif