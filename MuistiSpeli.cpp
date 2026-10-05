#include "MuistiSpeli.h"
#include "LedJarjestys.h"
#include "Satunnaisluku.h"
#include "buttons.h"
#include "display.h"
#include "leds.h"

bool gameOver = false;
bool checkGame(int nappiPainettu, int& laskuri, int& nopeus) { //checkGame himmeli. Pyörähtää aina napin painalluksella niin kauan kunhan eventQueySize on alle 30

  int ledArvo = kurkista_ledjarjestys();

  if (ledArvo != -1 && ledArvo == nappiPainettu) { // jos oikea painallus
    pop_ledjarjestys(); //paukautetaan jonosta seuraava
    laskuri++;
    setScore(laskuri);
    //updateDisplay(laskuri); // päivitetään näytölle pisteet. Nimeäminen mitä ikinä Eetu keksii display.h nimetä.

    if (laskuri % 10 == 0) // jos 10 oikeaa painallusta, niin peli nopeutuu
    {
      nopeus = max(100, (int)(nopeus * 0.9)); // ledejen vilkkuminen. Ei varmuutta toimiiko näin vai pitääkö muuttaa esim "- 100"
    }
  }

  // if (ledArvo != -1 && nappiPainettu != -1 && ledArvo != nappiPainettu) { // jos väärä painallus
  //   gameOver = true;
  // }

  if (eventQueueSize() > 30) {
    gameOver = true;
  }
  return gameOver;
}
void startTheGame() {
  
  gameOver = false;
  //setScore(0);
  //updateDisplay(0);
  //initializeLeds();
  //initButtonsAndButtonInterrupts(); //näytön alustus tulleepi tähän. MUISTA TÄYDENTÄÄ!! initButtonsAndButtonInterrupts
  initializeEventQueue(); // jonon alustus
  alustaSatunnaisluku();
  unsigned long aikaaKulunut = 0;
  int nappiPainettu = -1;
  int nopeus = 1000;
  int laskuri = 0;

  while (!gameOver) {
    setScore(laskuri);
    //updateDisplay(laskuri);
    if (millis() - aikaaKulunut > nopeus) { // jatkuva ledejen lisäys
      int uusiLed = haeSatunnainenLed();
      lisaa_ledjarjestys(uusiLed);
      blink(uusiLed);
      aikaaKulunut = millis();
    }
    int nappiPainettu = readButton();  // Mikaelin tekemä buttons.cppn funktio mikä tuo painetun napin. NIMETTÄVÄ UUDELLEEN LUULTAVASTI
    if (checkGame(nappiPainettu, laskuri, nopeus)) {
      show2(5); // mikä ikinä nimeksi tulle. HUOM MUISTA MUUTTAA
      break;
    }
  }
}



