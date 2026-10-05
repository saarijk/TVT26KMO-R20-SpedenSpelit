#include <Arduino.h>
#include "buttons.h"
#include "leds.h"
#include "display.h"
#include "satunnaisluku.h"

// Pelit
#include "MuistiSpeli.h"
//#include "NoppaPeli.h"


//int score = 0;
void setup()
{
    //int score = 0;
    //setupDisplay();
    initializeDisplay();
    initButtonsAndButtonInterrupts();
    initializeLeds();
    clearAllLeds();
    alustaSatunnaisluku();
    //testSegmentsIndividually();
    // Näytetään alkuun 00
    //showScore(0);
}

void loop()
{

    ///setScore(score);
    int nappi = readButton();

    if (nappi == -1)
        return; 


    // Käynnistä MuistiSpeli

    if (digitalRead(2) == LOW && digitalRead(5) == LOW)
    {
        show2(5);          // LED-valoshow ennen pelin alkua
        startTheGame();   // Muistipeli
        return;
    }

    // Käynnistä NoppaSpeli (napit 2 + 3)
    if (digitalRead(4) == LOW && digitalRead(3) == LOW)
    {
        show2(15);          // LED-valoshow ennen pelin alkua
        //NoppaSpeli();  // Noppapeli
        return;
    }

    // Muuten odotetaan uusia painalluksia
}

