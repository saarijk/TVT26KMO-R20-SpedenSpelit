#include "display.h"
#include "buttons.h"
#include "leds.h"
#include "SpedenSpelit.h"

// tavoitteena se, että keskeytykset asettavat nämä liput, ja loop() käsittelee ne
volatile int buttonNumber = -1;
volatile bool newTimerInterrupt = false;


void setup()
{
  // tähän tulee alustukset: initializeLeds(), initializeButtons(),
  // initializeDisplay(), initializeEventQueue(), ja alustaSatunnaisluku()
  // Konfiguroidaan timeri kun peli on valmis alkamaan

  // Väliaikainen LED demo
  initializeLeds();
  clearAllLeds();

  show1();
  show2(10);
  clearAllLeds();
}

void loop()
{
  // toimii koordinaattorina
  // tarkistaa onko nappia painettu ja onko timeri-interrupt tapahtunut
  // toiminnallisuus SpedenSpelit.cpp:ssä, loop() vain kutsuu funktioita

  if(buttonNumber>=0)
  {
     // start the game if buttonNumber == 4
     // check the game if 0<=buttonNumber<4
  }

  if(newTimerInterrupt == true)
  {
     // new random number must be generated
     // and corresponding let must be activated
  }
}

// Timerin alustuksen ja keskeytyskäsittelijän voisi siirtää SpedenSpelit.cpp:hen
void initializeTimer(void)
{
	// see requirements for the function from SpedenSpelit.h
}
ISR(TIMER1_COMPA_vect)
{
  /*
  Communicate to loop() that it's time to make new random number.
  Increase timer interrupt rate after 10 interrupts.
  */
  
}


// toiminnallisuuden voisi siirtää SpedenSpelit.cpp:hen
// tässä tiedostossa säilytetään vain alustukset ja 
// timeri-interruptin määrittely
void checkGame(byte nbrOfButtonPush)
{
	// see requirements for the function from SpedenSpelit.h
}


void initializeGame()
{
	// see requirements for the function from SpedenSpelit.h
}

void startTheGame()
{
   // see requirements for the function from SpedenSpelit.h
}

