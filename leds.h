#ifndef LEDS_H
#define LEDS_H

#include <Arduino.h>

void initializeLeds();

void clearAllLeds();

void setAllLeds();

void blink(int led);

void startShow();

void endShow1(int rounds);

#endif