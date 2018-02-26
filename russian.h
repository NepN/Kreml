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
       
};

#include "russian_functions.h"
#include "russian_actions.h"

#endif // RUSSIAN_H