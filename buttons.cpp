#include "buttons.h"
#include "event_queue.h"
#include <avr/interrupt.h>

const byte BUTTON_0 = 2;
const byte BUTTON_1 = 3;
const byte BUTTON_2 = 4;
const byte BUTTON_3 = 5;


// painikkeiden edellinen tila
volatile byte previousButtonState = 0;

// painikkeiden alustus
void initializeButtons()
{
    pinMode(BUTTON_0, INPUT_PULLUP);
    pinMode(BUTTON_1, INPUT_PULLUP);
    pinMode(BUTTON_2, INPUT_PULLUP);
    pinMode(BUTTON_3, INPUT_PULLUP);
}


// PAINIKKEIDEN LUKEMINEN
// Tätä voidaan käyttää pelin startissa
int readButton()
{
    if (digitalRead(BUTTON_0) == LOW)
        return 0;

    if (digitalRead(BUTTON_1) == LOW)
        return 1;

    if (digitalRead(BUTTON_2) == LOW)
        return 2;

    if (digitalRead(BUTTON_3) == LOW)
        return 3;

    return -1;
}


// keskeytyksen alustus
void initButtonsAndButtonInterrupts(void)
{
    // pinnit D2-D5 inputiksi
    DDRD &= ~(
        (1 << DDD2) |
        (1 << DDD3) |
        (1 << DDD4) |
        (1 << DDD5)
    );

    // sisäiset pull-up-vastukset päälle
    PORTD |= (
        (1 << PORTD2) |
        (1 << PORTD3) |
        (1 << PORTD4) |
        (1 << PORTD5)
    );

    // tallennetaan painikkeiden nykyinen tila
    previousButtonState = PIND;

    // port D:n Pin Change Interrupt käyttöön
    PCICR |= (1 << PCIE2);

    // D2-D5 voivat aiheuttaa keskeytyksen
    PCMSK2 |=
        (1 << PCINT18) |
        (1 << PCINT19) |
        (1 << PCINT20) |
        (1 << PCINT21);

    // globaalit keskeytykset päälle
    sei();
}

// keskeytykset
ISR(PCINT2_vect)
{
    // luetaan Port D:n nykyinen tila
    byte currentButtonState = PIND;

    // selvitetään mitkä bitit muuttuivat
    byte changed =
        currentButtonState ^ previousButtonState;

    // painike 1 / D2
    if ((changed & (1 << PIND2)) &&
        !(currentButtonState & (1 << PIND2)))
    {
        enqueueEvent(0);
    }

    // painike 2 / D3
    if ((changed & (1 << PIND3)) &&
        !(currentButtonState & (1 << PIND3)))
    {
        enqueueEvent(1);
    }

    // painike 3 / D4
    if ((changed & (1 << PIND4)) &&
        !(currentButtonState & (1 << PIND4)))
    {
        enqueueEvent(2);
    }

    // painike 4 / D5
    if ((changed & (1 << PIND5)) &&
        !(currentButtonState & (1 << PIND5)))
    {
        enqueueEvent(3);
    }
    // tallennetaan tila seuraavaa keskeytystä varten
    previousButtonState = currentButtonState;
}