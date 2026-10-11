#include "leds.h"
#include "display.h"

void initializeLeds()
{
    // initialise analog pins A2, A3, A4, A5 to be used as outputs
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
// void blink(int led) {
//     static unsigned long flashStart = 0;
//     static bool flashing = false;
//     static int flashLed = -1;

//     if (!flashing) {
//         flashing = true;
//         flashLed = led;
//         flashStart = millis();
//         setLed(led);
//     }

//     if (flashing && millis() - flashStart > 120) {
//         clearAllLeds();
//         flashing = false;
//         flashLed = -1;
//     }
// }

void startShow()
{
    static int i = 0;                  
    static unsigned long previousMillis = 0;
    static bool showRunning = true;
    const unsigned long interval = 500;
 
    if (!showRunning) {
        return;
    }
 
    unsigned long currentMillis = millis();
 
    if (currentMillis - previousMillis >= interval)
    {
        previousMillis = currentMillis;
 
        clearAllLeds();
 
        if (i & 0x01) setLed(0); // 1 = 0001
        if (i & 0x02) setLed(1); // 2 = 0010
        if (i & 0x04) setLed(2); // 4 = 0100
        if (i & 0x08) setLed(3); // 8 = 1000
 
        i++;
 
        if (i >= 16)
        {
            showRunning = false;
        }
    }
}
void endShow1(int rounds)
{
    for (int round = 0; round < rounds; round++)
    {
        for (int led = 0; led < 4; led++)
        {
            clearAllLeds();
            setLed(led);

            unsigned long startTime = millis();
            unsigned long duration = 100 + 50 * round;

            while (millis() - startTime < duration)
            {
                updateDisplay();
            }
        }
    }
    clearAllLeds();

    //show score for 20sec after the game ends
    unsigned long startTime = millis();

    while (millis() - startTime < 20000UL)
    {
        updateDisplay();
    }
    //clearDisplay();
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
    clearAllLeds();
}