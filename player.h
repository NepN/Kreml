#ifndef PLAYER_H
#define PLAYER_H

#include "russian.h"

#include "items.h"
class player : public items {
  private:
    russian* ilist[10];
    
  public:
    player(string n) 
        : items(n)
    {}
}; 

#endif // PLAYER_H