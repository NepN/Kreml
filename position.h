#ifndef POSITION_H
#define POSITION_H 

#include"russian.h"

class position {
  private:
    string name;
    russian* holder;
    int lvl;
    
  public:
    position(string n, int l, russian* r=NULL) {
      name = n;
      lvl = l;
      holder = r;
    }
};

#endif // POSITION_H