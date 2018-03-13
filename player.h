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
    
    void setinfluence(russian* ruski, int i) {
      ilist[i] = ruski;
    }
    void useinfluence(russian* ruski, int o) {
      if ( inlist(ruski) ) { // validate if ruski is in personal influencelist "ilist"
        if ( o < getI(ruski) ) { // check if new open influence is permitted (not an overstatement)
          // check if old influence is exceeded (not an understatement) will be done in class "russian"
          ruski->newinfluencer(this, o); // call method in "russian" to set new open influencer there
        }
      }
    }
    
   russian* getR(int i) {
      return ilist[i];
    }
    int getI(russian* ruski) { // BAUSTELLE
      for (int i : ilist) { // for each loop. Does it work?
        if (ilist[i] == ruski) return i;
      }
    }
    bool inlist(russian* ruski) {
      for (int i : ilist) { // for each loop. Does it work?
        if (ilist[i] == ruski) return 1;
      }
      return 0;
    }
}; 

#endif // PLAYER_H