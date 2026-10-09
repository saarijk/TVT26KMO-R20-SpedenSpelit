#include "MuistiSpeli.h"
#include "ledSequence.h"
#include "randomNumber.h"
#include "buttons.h"
#include "display.h"
#include "leds.h"

bool gameOver = false;
bool checkGame(int pressedButton, int& counter, int& speed) { //checkGame himmeli. Pyörähtää aina napin painalluksella niin kauan kunhan eventQueySize on alle 30

  int ledValue = peekLed();

  if (ledValue != -1 && ledValue == pressedButton) { // jos oikea painallus
    dequeueLed(); //paukautetaan jonosta seuraava
    counter++;
    setScore(counter);
    //updateDisplay(counter); // päivitetään näytölle pisteet. Nimeäminen mitä ikinä Eetu keksii display.h nimetä.

    if (counter % 10 == 0) // jos 10 oikeaa painallusta, niin peli nopeutuu
    {
      speed = max(100, (int)(speed * 0.9)); // ledejen vilkkuminen. Ei varmuutta toimiiko näin vai pitääkö muuttaa esim "- 100"
    }
  }

 // if (ledValue != -1 && pressedButton != -1 && ledValue != pressedButton) { // jos väärä painallus
 //gameOver = true;
  //}

  if (eventQueueSize() > 30) {
    gameOver = true;
  }
  return gameOver;
}
void startTheGame() {
  
  gameOver = false;
  //setScore(0);
  //updateDisplay(0);
  //initializeLeds();
  //initButtonsAndButtonInterrupts(); //näytön alustus tulleepi tähän. MUISTA TÄYDENTÄÄ!! initButtonsAndButtonInterrupts
  initializeEventQueue(); // initialize queue
  initializeRandomNumber();
  unsigned long elapsedTime = 0;
  int pressedButton = -1;
  int speed = 1000;
  int counter = 0;

  while (!gameOver)
{
    setScore(counter);
    updateDisplay();

    if (millis() - elapsedTime > speed)
    {
        int uusiLed = getRandomLed();
        enqueueLed(uusiLed);
        blink(uusiLed);
        elapsedTime = millis();
    }

    pressedButton = readButton();

    if (checkGame(pressedButton, counter, speed))
    {
        endShow1(5);
        break;
    }
  }
}


