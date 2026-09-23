#include "Satunnaisluku.h"

uint32_t satunnaislukuTila = 0;

void alustaSatunnaisluku() {
  satunnaislukuTila = analogRead(A3) ^ (micros() * 2654435761u); // micros() lisää ajallista vaihtelua käynnistyksestä. Tästä vois tulla siemen, joka on vaikeampi ennustaa kuin kumpikaan yksin. Ja tuossa tokassa esimerkissä on vielä Knuthin kerroin, jota on käytetty paljon satunnaislukujen siemennyksessä ja hashien teossa.
  if (satunnaislukuTila == 0) satunnaislukuTila = 0xCAFEBABE; // jos analogRead antaa nollan, niin arvoksi klassinen 32bit CAFEBABE
}
uint32_t satunnaisluku_0_3() {
  satunnaislukuTila ^= satunnaislukuTila << 13; //xorshiftataan 
  satunnaislukuTila ^= satunnaislukuTila >> 17;
  satunnaislukuTila ^= satunnaislukuTila << 5;
  return satunnaislukuTila; // palautetaan 0-3
}
uint8_t haeSatunnainenLed() {
  satunnaisluku_0_3();
  return satunnaislukuTila & 3;
}