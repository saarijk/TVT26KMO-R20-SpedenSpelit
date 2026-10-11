#include "SpedenSpelit.h"
#include "ledSequence.h"
#include "randomNumber.h"
#include "buttons.h"
#include "display.h"
#include "leds.h"
#include <util/atomic.h>

bool gameOver = false;

// check the button press, update the score, and detect game over
bool checkGame(int nappiPainettu, int& laskuri, unsigned long& ledOnDuration) {

  int ledArvo = peekLed();

  if (ledArvo != -1 && ledArvo == nappiPainettu) {
    dequeueLed();
    laskuri++;
    setScore(laskuri);
    if (laskuri % 10 == 0)
    {
      speedUpTimer();
      ledOnDuration = max(100UL, (ledOnDuration * 9UL) / 10UL);
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

// initialize and run the game until the player makes a mistake or the queue fills
void startTheGame() {
  gameOver = false;
  initializeEventQueue(); 
  initializeRandomNumber();
  startTimer();
  int nappiPainettu = -1;
  int laskuri = 0;
  unsigned long ledOnDuration = 1000UL;
  unsigned long ledTurnedOnAt = 0;
  bool ledIsOn = false;

  while (!gameOver) {
    setScore(laskuri);
    bool timerElapsed;
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
    {
      timerElapsed = newTimerInterrupt;
      newTimerInterrupt = false;
    }

    if (timerElapsed) {
      int uusiLed = getRandomLed();
      clearAllLeds();
      setLed(uusiLed);
      enqueueLed(uusiLed);
      ledTurnedOnAt = millis();
      ledIsOn = true;
    }

    ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
    {
      nappiPainettu = buttonNumber;
      buttonNumber = -1;
    }

    int previousScore = laskuri;
    bool isGameOver = checkGame(nappiPainettu, laskuri, ledOnDuration);
    if (laskuri > previousScore) {
      clearAllLeds();
      ledIsOn = false;
    }

    if (ledIsOn && millis() - ledTurnedOnAt >= ledOnDuration) {
      clearAllLeds();
      ledIsOn = false;
    }

    if (isGameOver) {
      stopTimer();
      endShow1(5);
      break;
    }
  }
}