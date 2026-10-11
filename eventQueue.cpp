#include "eventQueue.h"

namespace
{
const byte queueCapacity = 32;
volatile byte eventQueue[queueCapacity];
volatile byte queueHead = 0;
volatile byte queueTail = 0;
}

// reset the queue to an empty state
void initializeEventQueue()
{
	queueHead = 0;
	queueTail = 0;
}

// add an event to the queue unless it is full
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

// remove the next event from the queue
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

// read the next event without removing it from the queue
bool peekEvent(byte& event)
{
	if (queueTail == queueHead)
	{
		return false;
	}

	event = eventQueue[queueTail];
	return true;
}

// return the number of events currently in the queue
byte eventQueueSize()
{
	return (queueHead + queueCapacity - queueTail) % queueCapacity;
}
