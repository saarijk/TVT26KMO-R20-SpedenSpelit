#include "LedJarjestys.h"

void lisaa_ledjarjestys(int led) { //lisätään ledarvo jonoon
  enqueueEvent((byte)led);
}

int kurkista_ledjarjestys() { //kurkataan jonon ensimmäinen ledarvo
  byte event;
  if (dequeueEvent(event)) {
    enqueueEvent(event); // Peek by removing and re-adding to the tail
    return event;
  }
  return -1;
}

int pop_ledjarjestys() { //poistetaan jonon ensimmäinen ledarvo
  byte event;
  if (dequeueEvent(event)) return event;
  return -1;
}
