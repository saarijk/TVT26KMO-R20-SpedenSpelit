#include "SpedenSpelit.h"
#include "LedJarjestys.h"
#include "Satunnaisluku.h"
#include "buttons.h"
//#include "Start_game.h" // unkommataan, kun pelin aloitus on valmis
//#include "endgame.h" //unkommataan, kun pelin päättyminen lisätty 
#include "display.h"
#include "leds.h"



bool gameOver = false;
bool checkGame(int nappiPainettu, int& laskuri, int& nopeus) { //checkGame himmeli. Pyörähtää aina napin painalluksella niin kauan kunhan eventQueySize on alle 30

  int ledArvo = kurkista_ledjarjestys();

  if (ledArvo != -1 && ledArvo == nappiPainettu) { // jos oikea painallus
    pop_ledjarjestys(); //paukautetaan jonosta seuraava
    laskuri++;
    update_score(laskuri); // päivitetään näytölle pisteet. Nimeäminen mitä ikinä Eetu keksii display.h nimetä.

    if (laskuri % 10 == 0) // jos 10 oikeaa painallusta, niin peli nopeutuu
    {
      nopeus = max(100, (int)(nopeus * 0.9)); // ledejen vilkkuminen. Ei varmuutta toimiiko näin vai pitääkö muuttaa esim "- 100"
    }
  }

  if (eventQueueSize() > 30) {
    gameOver = true;
  }
  return gameOver;
}
void startTheGame() {
  
  initializeLeds();
  initButtonsAndButtonInterrupts(); //näytön alustus tulleepi tähän. MUISTA TÄYDENTÄÄ!! initButtonsAndButtonInterrupts
  initializeEventQueue(); // jonon alustus
  alustaSatunnaisluku();
  unsigned long aikaaKulunut = 0;
  int nopeus = 1000;
  int laskuri = 0;

  while (!gameOver) {
    if (millis() - aikaaKulunut > nopeus) {
      lisaa_ledjarjestys(haeSatunnainenLed());
      aikaaKulunut = millis();
    }
    int nappiPainettu = read_button_press();  // Mikaelin tekemä buttons.cppn funktio mikä tuo painetun napin. NIMETTÄVÄ UUDELLEEN LUULTAVASTI
    if (checkGame(nappiPainettu, laskuri, nopeus)) {
      endshow2();
      break;
    }
  }
}



