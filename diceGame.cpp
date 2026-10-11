#include "diceGame.h"
#include "display.h"
#include "eventQueue.h"
#include "leds.h"

namespace
{
const byte maximumRolls = 15;
bool diceGameActive = false;

// return a random value from 1 to 6
byte rollDie()
{
  return static_cast<byte>(random(1, 7));
}

// show the current roll count as a four-bit LED pattern
void showRollCount(byte count)
{
  clearAllLeds();
  for (byte led = 0; led < 4; ++led)
  {
    if (count & (1 << led))
    {
      setLed(led);
    }
  }
}

// add all queued rolls, empty the queue, and display their total
void showAndClearTotal()
{
  byte roll;
  uint16_t total = 0;

  while (dequeueEvent(roll))
  {
    total += roll;
  }

  showResult(static_cast<byte>(total));
}

// roll once, store the result, and update the roll-count LEDs
void rollDice()
{
  if (eventQueueSize() >= maximumRolls)
  {
    return;
  }

  byte value = rollDie();
  if (!enqueueEvent(value))
  {
    return;
  }

  byte rollCount = eventQueueSize();
  showRollCount(rollCount);

  if (rollCount == maximumRolls)
  {
    showAndClearTotal();
  }
}
}

// initialize the dice game and reset its queue and display
void startDiceGame()
{
  initializeEventQueue();
  randomSeed(analogRead(A3) ^ micros());
  clearAllLeds();
  setScore(0);
  diceGameActive = true;
}

// report whether the dice game is currently active
bool isDiceGameActive()
{
  return diceGameActive;
}

// handle roll and total button presses while the dice game is active
void handleDiceGameButton(int pressedButton)
{
  if (!diceGameActive)
  {
    return;
  }

  if (pressedButton == 1)
  {
    rollDice();
  }
  else if (pressedButton == 2)
  {
    showAndClearTotal();
  }
}

// leave the dice game and turn off all LEDs
void stopDiceGame()
{
  diceGameActive = false;
  clearAllLeds();
}
