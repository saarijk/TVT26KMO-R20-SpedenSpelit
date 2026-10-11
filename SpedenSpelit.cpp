#include "SpedenSpelit.h"
#include "ledSequence.h"
#include "randomNumber.h"
#include "buttons.h"
#include "display.h"
#include "leds.h"
#include <util/atomic.h>

bool gameOver = false;
bool checkGame(int nappiPainettu, int& laskuri) { //checkGame himmeli

  int ledArvo = peekLed();

  if (ledArvo != -1 && ledArvo == nappiPainettu) { 
    dequeueLed(); 
    laskuri++;
    setScore(laskuri);
    if (laskuri % 10 == 0)
    {
      speedUpTimer();
    }
  }

  if (ledArvo != -1 && nappiPainettu != -1 && ledArvo != nappiPainettu) { 
    gameOver = true;
  }

  if (eventQueueSize() > 30) {
    gameOver = true;
  }
  return gameOver;
}

void startTheGame() {
  gameOver = false;
  initializeEventQueue(); 
  initializeRandomNumber();
  startTimer();
  int nappiPainettu = -1;
  int laskuri = 0;

  while (!gameOver) {
    setScore(laskuri);
    if (newTimerInterrupt) {
        newTimerInterrupt = false;
        int uusiLed = getRandomLed();
        clearAllLeds();
        setLed(uusiLed);
        enqueueLed(uusiLed);
    }

    ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
    {
      nappiPainettu = buttonNumber;
      buttonNumber = -1;
    }

    if (checkGame(nappiPainettu, laskuri)) {
      stopTimer();
      endShow1(5); // mikä ikinä nimeksi tulle. HUOM MUISTA MUUTTAA
      break;
    }
  }
}


