#include "randomNumber.h"

uint32_t randomNumberState = 0;

// seed the random-number generator using analog input and elapsed time
void initializeRandomNumber() {
  randomNumberState = analogRead(A3) ^ (micros() * 2654435761u);
  if (randomNumberState == 0) randomNumberState = 0xCAFEBABE;
}

// update the generator state and return a pseudorandom 32-bit value
uint32_t randomNumber_0_3() {
  randomNumberState ^= randomNumberState << 13;
  randomNumberState ^= randomNumberState >> 17;
  randomNumberState ^= randomNumberState << 5;
  return randomNumberState;
}

// return a random LED index from 0 to 3
uint8_t getRandomLed() {
  return randomNumber_0_3() & 3;
}