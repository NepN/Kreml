#ifndef GAME_H
#define GAME_H

#include "russian.h"
#include "player.h"
#include "position.h"

class game {
  private:
    russian* parades[8]; // argument 0 equals anno 1951
    russian* all[25]; // Liste der Russen verwalten. Ersetzen durch Datenbank?
  
  public:
    game() {
      cout << "Hi!" << endl;
    }
    
    void play() {
      initialize();
      for(int i=0; i<8; i++) {
        round();
        // anno++;
      }
    }
    
    void initialize() {
      russian aparatschik("Nestor Aparatschik", 1874);
      player leon("Leon");
      position chef("Parteichef",1);
      position KGB("KGB-Chef",2);
      // setinfluence
    }
    
    void round() {
      turn1();
    }
    
    void turn1() { // Phase 1: Kuren
      for (russian* ruski : all) {
        int a = ruski->gethealth(); 
        if ( a == 0 ) {
          if ruski->getcure() ruski->setcure(0);
        } else if ( a < 3 ) {
          ruski->setcure(ruski->askplayer());
        } else {
          // ruski is dead already
        }
      }
    }
    void turn2() { // Säuberungen
      player* atm = KGB.getholder()->getplayer();
      // Input von Player
      // Befehle für Turn 2 in Klasse "position" definieren? Sub-Klassen ("KGB", "defense" etc.) von "position" definieren und spezifische Methoden hinzufügen?!
    }
    void turn3() { // Imperialistischer Spion 
      
    }
    
    void turn4() { // Gesundheitszustand ermitteln
      // forall russians
        // ruski->healthCheck();
      if ( chef.getholder().gethealth() == 3 ) { 
        // ( || chef.getholder().getstate() == &dead )
        turn5();
      } else { 
        turn6();
      
    }
    void turn5() { // Wahl des BKV (Begräbniskommisions-Vorsitzender)
      
      turn6();
    }
    void turn6() { // Ersetzungen 
      
    }
    void turn7() { // Rehabilitation
      //
    }
    void turn8() { // Oktoberparade 
      
      ::anno++;
      checkvictory(); // or end condition
   }
};

#endif // GAME_H