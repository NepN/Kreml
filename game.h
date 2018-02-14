#ifndef GAME_H
#define GAME_H

#include "russian.h"

class game {
  private:
  
  public:
    game() {
      cout << "Hi!" << endl;
    }
    
    void initialize() {
      russian aparatschik("Nestor Aparatschik", 1874);
    }
};

#endif // GAME_H