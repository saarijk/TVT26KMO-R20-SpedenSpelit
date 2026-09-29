#include "LedJarjestys.h"

void lisaa_ledjarjestys(int led) { //lisätään ledarvo jonoon
  enqueueEvent((byte)led);
}

int kurkista_ledjarjestys() { //kurkataan jonon ensimmäinen/vanhin ledarvo
  byte event;
  if (peekEvent(event)) return event;
  return -1;
}

int pop_ledjarjestys() { //poistetaan jonon ensimmäinen/vanhin ledarvo
  byte event;
  if (dequeueEvent(event)) return event;
  return -1;
}
