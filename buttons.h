#ifndef BUTTONS_H
#define BUTTONS_H

#include <Arduino.h>

void initializeButtons();

byte readButton();

bool startButtonsPressed();

#endif