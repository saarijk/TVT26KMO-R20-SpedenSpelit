#ifndef SATUNNAISLUKU_H
#define SATUNNAISLUKU_H

#include <Arduino.h>

extern uint32_t satunnaislukuTila; //tätä muuttujaa xorshiftataan

void alustaSatunnaisluku(); //lukee pinnistä A3 arvon

uint32_t satunnaisluku_0_3(); //satunnaisluku 0-3

#endif // SATUNNAISLUKU_H
