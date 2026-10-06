#ifndef BUTTONS_H
#define BUTTONS_H

#include <Arduino.h>

void initializeButtons();

int readButton();

bool startButtonsPressed();

#endif