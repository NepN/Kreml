#ifndef RUSSIAN_H
#define RUSSIAN_H

#include "place.h"
#include "player.h"

#include "items.h"
class russian : public items {
  private:
    int birth;
    int health;
    int stress;
    place* state;
    bool cure;
    
    void sethealth(int a) {
      addhealth(health+a);
    }
    void addhealth(int a) {
      health += a;
      correcthealth();
    }
    void correcthealth() {
      if (health<0) {
        health = 0;
      } else if (health>3=) { 
        health = 3;
        state = ::dead*;
    }
    
    player* influencer;
    int oinfluence; // highest amount a player (is current influencer) has showed 
    
 public:
    russian(string n, int b, int h=0) 
      : items(n)
    {
      birth = b;
      health = h;
      stress = 0;
      state = ::plebs*; // global vordefiniert
    }
    
   int getage() {
      return (realage()+stress);
    }
    int realage() {
      return (1951-birth); 
    }
    
    // health-values
    int gethealth() return health;
    void healthCheck() {
      // roll W20 dice 
      int w = rand() % 20;
      cout << "W = " << w << endl;
      
      // determine right table and result (result value equals change of health)
      int c;
      if (state) { 
        c = ::work.getH(age(),w); // global vordefiniert
      } else { 
        c = ::cure.getH(age(),w); // global vordefiniert
      }
      // apply change of health to russian's health stat 
      addhealth(c);
    }
    
    player* getplayer() {
      return influencer;
    }
    
    void newinfluencer(player* raiser, int o) {
      if (oinfluence<o) {
        influencer = raiser;
        oinfluence = o;
      } else {
        cout << "Ihr Einfluss reicht nicht aus." << endl;
    }
    
    void rehab(russian* ruski) {
      if (ruski->state == &sibiria) { // validate ruski is in sibiria
        // Zulässigkeiten der Auswahl sollten bei Eingabe abgefragt / sichergestellt werden
        // nicht in jeder Funktion
        ruski->state = &plebs;
        stress += 5;
      }
    }
    void parade() {
      int w = rand() % 20 + 1;
      switch (health)
      {
        case 2: 
          stress += 2;
          if (w>=15) {
            // add event to parade-list
          }
          break;
        case 1: 
          stress += 1;
          if (w>=8) {
            // add event to parade-list
          }
          break;
        case 0: 
          // add event to parade-list
        default:
          cout << "Die Parade konnte nicht beendet werden." << endl; 
      }
         
    }
};

#endif // RUSSIAN_H