#include "SpedenSpelit.h"
#include "ledSequence.h"
#include "randomNumber.h"
#include "buttons.h"
//#include "Start_game.h" // unkommataan, kun pelin aloitus on valmis
//#include "endgame.h" //unkommataan, kun pelin päättyminen lisätty 
#include "display.h"
#include "leds.h"

extern void initializeTimer(void);
extern void startTimer(void);
extern void speedUpTimer(void);
extern void stopTimer(void);
extern volatile uint16_t timerTicks;

bool gameOver = false;

bool checkGame(int pressedButton, int& counter) { //checkGame helper. It rotates every time a button is pressed as long as eventQueueSize is below 30.

  int ledValue = peekLed();

  if (ledValue != -1 && ledValue == pressedButton) { // correct button press
    dequeueLed(); // remove the next value from the queue
    counter++;
    setScore(counter); // update the score shown on the display

    if (counter % 10 == 0) // every 10 correct presses, speed up the game
    {
      speedUpTimer();
    }
  }
  // TODO: handle a wrong button press

  if (eventQueueSize() > 30) {
    gameOver = true;
    stopTimer();
    timerTicks = 0;
  }
  return gameOver;
}

void startTheGame() {
  initializeLeds();
  initButtonsAndButtonInterrupts();
  initializeEventQueue();
  initializeRandomNumber();
  initializeTimer();

  gameOver = false;
  timerTicks = 0;
  int counter = 0;
  int pressedButton = -1;

  startTimer();

  while (!gameOver) {
    while (timerTicks > 0) {
      timerTicks--;
      enqueueLed(getRandomLed());
    }

    pressedButton = readButton();

    if (checkGame(pressedButton, counter)) {
      stopTimer();
      timerTicks = 0;
      endShow1(5);
      break;
    }
  }
}

