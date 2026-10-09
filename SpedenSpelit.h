#ifndef SPEDENSPELIT_H
#define SPEDENSPELIT_H

#include <Arduino.h>

// Shared gameplay API used by the game logic and Arduino entry points.
bool checkGame(int buttonPressed, int& score, int& speed);
void startTheGame(void);

#endif