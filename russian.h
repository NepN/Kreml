#ifndef RUSSIAN_H
#define RUSSIAN_H

#include "place.h"
#include "player.h"

#include "items.h"
class russian : public items {
  private:
    // values
    int birth;
    int health;
    int stress;
    place* state;
    // token
    bool cure;
    bool suspicious;
    
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
      cure = false;
      suspicious = false;
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
    
    place* getstate() {
      return state;
    }
    void setstate(state* val) {
      state = val;
    } 
    bool getcure() {
      return cure;
    }
    void setcure(bool val) {
      cure = val;
    }
    bool askplayer(string n) {
      if ( n == "cure" ) { // umwandeln in switch-case mit hash-funktion (enum) oder ähnliches
        cout << "Soll dieser Charakter in Kur gehen/bleiben?" << endl;
        bool a;
        // cin >> a;
        return a;
      } else if ( n == "purge") {
        cout << "Wollen Sie einen Genossen wegsäubern?" << endl;
        bool a;
        // cin >> a;
        return a;
      } 
    } // templatisieren für verschiedene return-Datentypen (bool, russian*, ...)
    russian* askplayerconcrete(string n) {
      if ( n == "purge" ) {
        cout << "Wen wollen Sie säubern?" << endl;
        russian* purged;
        // cin >> &purged;
        return purged;
      }
    }
    
    bool spy() {
      return suspicious;
    }
    void suspicion(bool a) {
      suspisious = a;
    }
    void addstress(int a) {
      stress += a;
    }
};

#endif // RUSSIAN_H