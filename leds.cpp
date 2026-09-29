#include "leds.h"


void initializeLeds()
{
    // initialise digital pins 6,7,9,10 to be used as outputs
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT); 
}

void setLed(byte ledNumber)
{
    // set number (0, 1, 2 or 3) to correspond to pins
    switch(ledNumber)
    {
        case 0:
            digitalWrite(6, HIGH);
            break;
        case 1:
            digitalWrite(7, HIGH);
            break;
        case 2:
            digitalWrite(9, HIGH);
            break;
        case 3:
            digitalWrite(10, HIGH);
            break;
        default:
            // do nothing?
            break;
    }

}


void clearAllLeds()
{
    // clear all leds
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
}

void setAllLeds()
{
    // set all leds
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
}


void startShow()
// start show
{
    // light up leds as binary representation of 0-15
    // could use a loop: for each number, figure out which bits are 1
    // turn the corresponding led on or off
    // wait a bit and repeat

    for (int i = 0; i < 16; i++)
    {
        clearAllLeds();

        // check each bit of i and set corresponding led
        if (i & 0x01) setLed(0); // 1 = 0001
        if (i & 0x02) setLed(1); // 2 = 0010
        if (i & 0x04) setLed(2); // 4 = 0100
        if (i & 0x08) setLed(3); // 8 = 1000

        delay(500);
    }
}

void EndShow1(int rounds)
// end show, when pressed wrong button
{
    // cycle through leds with increasing speed
    for (int round = 0; round < rounds; round++)
    {
        for (int led = 0; led < 4; led++)
        {
            clearAllLeds();
            setLed(led);
            // increase speed each round
            delay(50 + 100 / (round + 1));
        }
    }
}
void EndShow2()
// end show 2, when led calculator is full
{
    setAllLeds();
    delay(1000);

    clearAllLeds();
    delay(250)

    SetAlleds();
    delay(1000);

    digitalWrite(10, LOW);  // LED 4
    delay(500);

    digitalWrite(9, LOW);   // LED 3
    delay(500);

    digitalWrite(7, LOW);   // LED 2
    delay(500);

    digitalWrite(6, LOW);   // LED 1
    delay(500);
    }
