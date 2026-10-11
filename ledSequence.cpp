#include "LedSequence.h"

// add an LED index to the event queue
void enqueueLed(int led) {
  enqueueEvent((byte)led);
}

// return the next queued LED without removing it
int peekLed() {
  byte event;
  if (peekEvent(event)) return event;
  return -1;
}

// remove and return the next queued LED
int dequeueLed() {
  byte event;
  if (dequeueEvent(event)) return event;
  return -1;
}