#ifndef PLACE_H
#define PLACE_H

#include "items.h"
class place : public items {
  private:

  public:
    place(string n)
      : items(n)
    {}

};

place sana("Sanatorium");
place city("Stadt");
place sibiria("Sibirien");
place dead("Friedhof");

#endif // PLACE_H
