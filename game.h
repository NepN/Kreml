#ifndef GAME_H
#define GAME_H

#include "russian.h"
#include "player.h"
#include "position.h"

class game {
  private:
  
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
      // setinfluence
    }
    
    round() {
      turn1();
    }
    
    turn1() { // Phase 1: Kuren
      // forall ill russians
        // askcure();
    }
};

#endif // GAME_H