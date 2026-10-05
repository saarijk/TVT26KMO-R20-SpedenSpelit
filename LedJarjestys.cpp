#include "LedJarjestys.h"

void lisaa_ledjarjestys(int ledArvo) { //lisätään ledarvo jonoon
  enqueueEvent((byte)ledArvo);
}

int kurkista_ledjarjestys() { //kurkataan jonon ensimmäinen ledarvo
  byte event;
  if (peekEvent(event)) return event;
  return -1;
}

int pop_ledjarjestys() { //poistetaan jonon ensimmäinen ledarvo
  byte event;
  if (dequeueEvent(event)) return event;
  return -1;
}
