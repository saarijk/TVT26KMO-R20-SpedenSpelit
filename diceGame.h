#ifndef DICEGAME_H
#define DICEGAME_H
#include <Arduino.h>

void startDiceGame();
bool isDiceGameActive();
void handleDiceGameButton(int pressedButton);
void stopDiceGame();

#endif