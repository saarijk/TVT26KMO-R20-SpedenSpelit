#include "randomNumber.h"

uint32_t randomNumberState = 0;

void initializeRandomNumber() {
  randomNumberState = analogRead(A3) ^ (micros() * 2654435761u); // micros() lisää ajallista vaihtelua käynnistyksestä. Tästä vois tulla siemen, joka on vaikeampi ennustaa kuin kumpikaan yksin. Ja tuossa tokassa esimerkissä on vielä Knuthin kerroin, jota on käytetty paljon satunnaislukujen siemennyksessä ja hashien teossa.
  if (randomNumberState == 0) randomNumberState = 0xCAFEBABE; // jos analogRead antaa nollan, niin arvoksi klassinen 32bit CAFEBABE
}

uint32_t randomNumber_0_3() {
  randomNumberState ^= randomNumberState << 13; // xorshiftataan
  randomNumberState ^= randomNumberState >> 17;
  randomNumberState ^= randomNumberState << 5;
  return randomNumberState; // palautetaan 0-3
}

uint8_t getRandomLed() {
  return randomNumber_0_3() & 3;
}