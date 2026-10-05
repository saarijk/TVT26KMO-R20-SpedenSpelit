#include "MuistiSpeli.h"
#include "LedJarjestys.h"
#include "Satunnaisluku.h"
#include "buttons.h"
#include "display.h"
#include "leds.h"

bool gameOver = false;
bool checkGame(int nappiPainettu, int& laskuri) { //checkGame himmeli

  int ledArvo = kurkista_ledjarjestys();

  if (ledArvo != -1 && ledArvo == nappiPainettu) { 
    pop_ledjarjestys(); 
    laskuri++;
    setScore(laskuri);
    if (laskuri % 10 == 0)
    {
      speedUpTimer();
    }
  }

  if (ledArvo != -1 && nappiPainettu != -1 && ledArvo != nappiPainettu) { 
    gameOver = true;
  }

  if (eventQueueSize() > 30) {
    gameOver = true;
  }
  return gameOver;
}
void startTheGame() {
  
  gameOver = false;
  initializeEventQueue(); 
  alustaSatunnaisluku();
  startTimer();
  int nappiPainettu = -1;
  int laskuri = 0;

  while (!gameOver) {
    setScore(laskuri);
    if (newTimerInterrupt) {
        newTimerInterrupt = false;
        int uusiLed = haeSatunnainenLed();
        clearAllLeds();
        setLed(uusiLed);
        lisaa_ledjarjestys(uusiLed);
    }
    nappiPainettu = readButton(); 
    if (checkGame(nappiPainettu, laskuri)) {
      stopTimer();
      show2(5); // mikä ikinä nimeksi tulle. HUOM MUISTA MUUTTAA
      break;
    }
  }
}



