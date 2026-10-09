#ifndef MUISTISPELI_H
#define MUISTISPELI_H

#include <Arduino.h>

void startTheGame(void);
bool checkGame(int pressedButton, int& counter, int& speed);
void startTimer(void);
void stopTimer(void);
void speedUpTimer(void);

extern volatile bool newTimerInterrupt;
#endif