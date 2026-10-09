#include "MuistiSpeli.h"
#include "buttons.h"
#include "display.h"
#include "eventQueue.h"
#include "leds.h"
#include "randomNumber.h"
#include <util/atomic.h>

volatile int buttonNumber = -1;
volatile uint16_t timerTicks = 0;

namespace
{
  // constants for Timer1 configuration
  // starting comparison value
  const uint16_t initialTimerCompare = (F_CPU / 1024UL) - 1;
  // lowest comparison value, corresponding to 0.1 sec 
  // sets the limit on how fast the timer can go 
  const uint16_t minimumTimerCompare = (F_CPU / 10240UL) - 1;
}

// prep everything
void setup()
{
  
  initializeLeds();
  clearAllLeds();
  initializeButtons();
  initializeDisplay();
  // initializeEventQueue();
  initializeRandomNumber();
  initializeTimer();
  Serial.begin(9600);
}

// read the latest button event and handle a game start or player input
void loop()
{
  int pressedButton;
  ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
  {
    pressedButton = buttonNumber;
    buttonNumber = -1;
  }

  // Check button combinations before handling individual button events.
  if (digitalRead(2) == LOW && digitalRead(5) == LOW)
  {
    startShow();
    startTheGame();
    return;
  }

  if (digitalRead(4) == LOW && digitalRead(3) == LOW)
  {
    startShow();
    // NoppaSpeli(); // Noppapeli
    return;
  }

  if (pressedButton == 3)
  {
    endShow1(5);
    startTheGame();
  }
}

// configure Timer1 but leave it stopped until a game starts
void initializeTimer(void)
{
  TCCR1A = 0;
  TCCR1B = _BV(WGM12); 
  TCNT1 = 0; 
  OCR1A = initialTimerCompare; 
  TIFR1 = _BV(OCF1A); 
  TIMSK1 &= ~_BV(OCIE1A);
  timerTicks = 0;
}

// reset Timer1 and start it with its initial one-second interval
// call this after game setup, just before the gameplay loop
// so the first timer interval starts with play
void startTimer(void)
{
  TCNT1 = 0; 
  OCR1A = initialTimerCompare; 
  TIFR1 = _BV(OCF1A); 
  timerTicks = 0;
  TIMSK1 |= _BV(OCIE1A);
  TCCR1B = _BV(WGM12) | _BV(CS12) | _BV(CS10);
}

// shorten the timer interval by 10%, down to a minimum of 0.1 seconds
void speedUpTimer(void)
{
  uint32_t nextCompare = (static_cast<uint32_t>(OCR1A) * 9UL) / 10UL;
  if (nextCompare < minimumTimerCompare)
  {
    nextCompare = minimumTimerCompare;
  }

  // prevent the timer interrupt from changing the counter during this update
  ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
  {
    OCR1A = static_cast<uint16_t>(nextCompare);

    if (TCNT1 >= nextCompare)
    {
      TCNT1 = 0;
    }
  }
}

// stop Timer1 and clear its pending interrupt event
void stopTimer(void)
{
  TCCR1B = _BV(WGM12); 
  TIMSK1 &= ~_BV(OCIE1A); 
  TIFR1 = _BV(OCF1A); 
  timerTicks = 0;
}

// runs when Timer1 reaches its compare value and signals that an interval passed
ISR(TIMER1_COMPA_vect)
{
  timerTicks++;
}

// checkGame, initializeGame, startTheGame siirretty SpedenSpelit.cpp:hen