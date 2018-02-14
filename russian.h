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
    
    player* influencer;
    int oinfluence; // highest amount a player (is current influencer) has showed 
     
  public:
    russian(string n, int b, int h=0) 
      : items(n)
    {
      birth = b;
      health = h;
      stress = 0;
      state = false;
    }
    
    string getname() {
      return name;
    }
    int getage() {
      return (realage()+stress);
    }
    int realage() {
      return (1951-birth); 
    }
    
}

#endif // RUSSIAN_H