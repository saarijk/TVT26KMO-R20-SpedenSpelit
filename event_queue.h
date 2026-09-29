#ifndef EVENT_QUEUE_H
#define EVENT_QUEUE_H

#include <Arduino.h>

void initializeEventQueue();
bool enqueueEvent(byte event);
bool dequeueEvent(byte& event);
byte eventQueueSize();

#endif