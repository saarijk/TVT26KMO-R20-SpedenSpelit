#ifndef EVENTQUEUE_H
#define EVENTQUEUE_H
#include <Arduino.h>

void initializeEventQueue();
bool enqueueEvent(byte event);
bool dequeueEvent(byte& event);
bool peekEvent(byte& event);
byte eventQueueSize();

#endif