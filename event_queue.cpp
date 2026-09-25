#include "event_queue.h"

namespace
{
const byte queueCapacity = 6;
volatile byte eventQueue[queueCapacity];
volatile byte queueHead = 0;
volatile byte queueTail = 0;
}

void initializeEventQueue()
{
	queueHead = 0;
	queueTail = 0;
}

bool enqueueEvent(byte event)
{
	byte nextHead = (queueHead + 1) % queueCapacity;

	if (nextHead == queueTail)
	{
		return false;
	}

	eventQueue[queueHead] = event;
	queueHead = nextHead;
	return true;
}

bool dequeueEvent(byte& event)
{
	if (queueTail == queueHead)
	{
		return false;
	}

	event = eventQueue[queueTail];
	queueTail = (queueTail + 1) % queueCapacity;
	return true;
}

byte eventQueueSize()
{
	return (queueHead + queueCapacity - queueTail) % queueCapacity;
}
