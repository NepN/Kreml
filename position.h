#ifndef POSITION_H
#define POSITION_H 

#include"russian.h"

#include "items.h"
class position : public items {
  private:
    russian* holder;
    int lvl;
    
  public:
    position(string n, int l, russian* r=NULL) 
      : items(n)
    {
      lvl = l;
      holder = r;
    }
    
    russian* getholder() {
      return holder; 
    }
};

#endif // POSITION_H