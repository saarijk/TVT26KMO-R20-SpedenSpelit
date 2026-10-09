#ifndef LEDSEQUENCE_H
#define LEDSEQUENCE_H

#include "eventQueue.h"

void enqueueLed(int led);
int peekLed();
int dequeueLed();

#endif