#include "LedSequence.h"

void enqueueLed(int led) {
  enqueueEvent((byte)led);
}

int peekLed() {
  byte event;
  byte e;
  peekEvent(e);
  Serial.print("peek: ");
  Serial.println(e);
  if (peekEvent(event)) return event;
  return -1;
}

int dequeueLed() {
  byte event;
  if (dequeueEvent(event)) return event;
  return -1;
}