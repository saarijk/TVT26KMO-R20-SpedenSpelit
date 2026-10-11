#ifndef RANDOMNUMBER_H
#define RANDOMNUMBER_H
#include <Arduino.h>

// seed the random-number generator using analog input A3
void initializeRandomNumber();
// return a pseudorandom 32-bit value
uint32_t randomNumber_0_3();
// return a random LED index from 0 to 3
uint8_t getRandomLed();

#endif
