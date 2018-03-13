#ifndef RUSSIAN_H
#define RUSSIAN_H

#include "place.h"
class player;
#include "health.h"

#include <stdlib.h> /* srand, rand */

#include "items.h"
class russian : public items {
  private:
    // values
    int birth;
    int hval;
    int stress;
    place* state;
    // token
    bool cure;
    bool suspicious;

    void sethealth(int a) {
      addhealth(hval+a);
    }
    void addhealth(int a) {
      hval += a;
      correcthealth();
    }
    void correcthealth() {
      if (hval<0) {
        hval = 0;
      } else if (hval>=3) {
        hval = 3;
        state = &dead;
      }
    }

    player* influencer;
    int oinfluence; // highest amount a player (is current influencer) has showed

 public:
    russian(string n, int b, int h=0)
      : items(n)
    {
      birth = b;
      hval = h;
      stress = 0;
      state = &city; // global vordefiniert
      cure = false;
      suspicious = false;
    }

// #include "russian_functions.h"
  // Alter und Stress
    int realage()
      { return (1951- birth); }
    int getage()
      { return (realage()+stress); }
   void addstress(int a)
      { stress += a; }

 // Zustände
    place* getstate()
      { return state; }
    void setstate(place* val)
      { state = val; }
    bool getcure()
      { return cure; }
    void setcure(bool val)
      { cure = val; }
     bool spy() {
      return suspicious;
    }
    void suspicion(bool a) {
      suspicious = a;
    }


  // Einflüsse
    player* getplayer()
      { return influencer; }
    void newinfluencer(player* raiser, int o) {
      if (oinfluence<o) {
        influencer = raiser;
        oinfluence = o;
      } else {
        cout << "Ihr Einfluss reicht nicht aus." << endl;
      }
    }


// #include "russian_actions.h"
  // Turn 1: Kuren
  // Turn 3: Säuberungen
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

  // Turn 4: Gesundheitszustand ermitteln
    // health-values
    int gethealth() { return hval; }
    void healthCheck() {
      // roll W20 dice
      int w = rand() % 20;
      cout << "W = " << w << endl;

      // determine right table and result (result value equals change of health)
      int c;
      if (state->getname() == "Politburo") {
        c = work.getH(getage(),w); // global vordefiniert
      } else {
        c = cure.getH(getage(),w); // global vordefiniert
      }
      // apply change of health to russian's health stat
      addhealth(c);
    }

  // Turn 7: Rehabilitation
    void rehab(russian* ruski) {
      if (ruski->state == &sibiria) { // validate ruski is in sibiria
        // Zulässigkeiten der Auswahl sollten bei Eingabe abgefragt / sichergestellt werden
        // nicht in jeder Funktion
        ruski->state = &city;
        stress += 5;
      }
    }

  // Turn 8: Oktoberparade
    void parade() {
      int w = rand() % 20 + 1;
      switch (hval)
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
