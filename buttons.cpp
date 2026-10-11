#include "buttons.h"
#include <avr/interrupt.h>
volatile int buttonNumber = -1;
volatile int lastButtonState = -1;
volatile unsigned long lastInterruptTime = 0;
const unsigned long debounceDelay = 50;
void initializeButtons(void)
{
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  PCICR |= (1 << PCIE2);

    // sisäiset pull-up-vastukset päälle
    PORTD |= 
        (1 << PORTD2) |
        (1 << PORTD3) |
        (1 << PORTD4) |
        (1 << PORTD5);
    // D2-D5 voivat aiheuttaa keskeytyksen
    PCMSK2 |=
        (1 << PCINT18) |
        (1 << PCINT19) |
        (1 << PCINT20) |
        (1 << PCINT21);
}

ISR(PCINT2_vect)
{
    unsigned long now = millis();
    if (now - lastInterruptTime < debounceDelay)
        return;

    lastInterruptTime = now;

    if (digitalRead(2) == LOW) buttonNumber = 0;
    else if (digitalRead(3) == LOW) buttonNumber = 1;
    else if (digitalRead(4) == LOW) buttonNumber = 2;
    else if (digitalRead(5) == LOW) buttonNumber = 3;
    else buttonNumber = -1;   // kaikki HIGH
}
int readButton() {
    static int previous = -1;
    int current = buttonNumber;

    if (current == previous)
        return -1;

    previous = current;
    return current;
}