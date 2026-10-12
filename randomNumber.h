#ifndef RANDOMNUMBER_H
#define RANDOMNUMBER_H

#include <Arduino.h>

void initializeRandomNumber(); //lukee pinnistä A3 arvon
uint32_t randomNumber_0_3(); //satunnaisluku 0-3 xorshiftaus
uint8_t getRandomLed(); // tätä kutsutaan, kun halutaan 0-3

#endif // RANDOMNUMBER_H
