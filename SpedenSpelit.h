#ifndef SPEDENSPELIT_H
#define SPEDENSPELIT_H

#include <Arduino.h>

void startTheGame(void);
bool checkGame(int nappiPainettu, int& laskuri, unsigned long& ledOnDuration);
void startTimer(void);
void stopTimer(void);
void speedUpTimer(void);

extern volatile bool newTimerInterrupt;
#endif