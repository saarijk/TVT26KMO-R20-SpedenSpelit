#ifndef MUISTISPELI_H
#define MUISTISPELI_H

#include <Arduino.h>

void startTheGame(void);
bool checkGame(int nappiPainettu, int& laskuri, int& nopeus);
#endif