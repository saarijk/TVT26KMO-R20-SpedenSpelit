#include "buttons.h"

const byte BUTTON_0 = 2;
const byte BUTTON_1 = 3;
const byte BUTTON_2 = 4;
const byte BUTTON_3 = 5;

void initializeButtons()
{
    pinMode(BUTTON_0, INPUT_PULLUP);
    pinMode(BUTTON_1, INPUT_PULLUP);
    pinMode(BUTTON_2, INPUT_PULLUP);
    pinMode(BUTTON_3, INPUT_PULLUP);
}

byte readButton()
{
    if (digitalRead(BUTTON_0) == LOW)
        return 0;

    if (digitalRead(BUTTON_1) == LOW)
        return 1;

    if (digitalRead(BUTTON_2) == LOW)
        return 2;

    if (digitalRead(BUTTON_3) == LOW)
        return 3;

    return 255;
}