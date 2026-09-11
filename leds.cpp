#include "leds.h"


void initializeLeds()
{
    // initialise analog pins A2, A3, A4, A5 to be used as outputs
    pinMode(A2, OUTPUT);
    pinMode(A3, OUTPUT);
    pinMode(A4, OUTPUT);
    pinMode(A5, OUTPUT); 
}

void setLed(byte ledNumber)
{
    // set number (0, 1, 2 or 3) to correspond to pins
    switch(ledNumber)
    {
        case 0:
            digitalWrite(A2, HIGH);
            break;
        case 1:
            digitalWrite(A3, HIGH);
            break;
        case 2:
            digitalWrite(A4, HIGH);
            break;
        case 3:
            digitalWrite(A5, HIGH);
            break;
        default:
            // do nothing?
            break;
    }

}


void clearAllLeds()
{
    // clear all leds
    digitalWrite(A2, LOW);
    digitalWrite(A3, LOW);
    digitalWrite(A4, LOW);
    digitalWrite(A5, LOW);
}

void setAllLeds()
{
    // set all leds
    digitalWrite(A2, HIGH);
    digitalWrite(A3, HIGH);
    digitalWrite(A4, HIGH);
    digitalWrite(A5, HIGH);
}


void show1()
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

void show2(int rounds)
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