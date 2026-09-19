#include "Satunnaisluku.h"

uint32_t satunnaislukuTila = 0;

void alustaSatunnaisluku() {
  satunnaislukuTila = analogRead(A3);
  if (satunnaislukuTila == 0) satunnaislukuTila =0xCAFEBABE; // jos analogRead antaa nollan, niin arvoksi klassinen 32bit CAFEBABE
}
uint32_t satunnaisluku_0_3(){
  satunnaislukuTila ^= satunnaislukuTila << 13; //xorshiftataan 
  satunnaislukuTila ^= satunnaislukuTila >> 17;
  satunnaislukuTila ^= satunnaislukuTila << 5;
  return satunnaislukuTila & 3; // palautetaan 0-3
}