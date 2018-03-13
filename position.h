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

    // turn2
    void purge() {
      bool allowance = true;
      while (allowance) {

      if (holder->askplayer("purge")) {

        russian* purged = holder->askplayerconcrete("purge");
        int dice = rand() % 20;
        if (purged->getcure()) dice += 3; // Bonus auf Wurf wenn in Kur
        bool success;

        switch (purged->lvl) {
          case 1:
            success = ( dice >= 18 );
          case 2:
            success = ( dice >= 14 );
          case 3:
            success = ( dice >= 10 );
          case 4:
            success = ( dice >=  6 );
          default:
            cout << "Das Volk bedarf unseres Schutzes und darf nicht gesäubert werden." << endl;
            success = false;
        }

        if (success) {
          purged->setstate(&sibiria);
          purged->suspicion(false);
          holder->addstress(1);
        } else {
          holder->addstress(3);
          allowance = false;
        }

      } else {
        allowance = false;
      } // enfif "purge"

    } // end_while
    } // end purge()

    void imperialspy() {

    }

};

position chef("Parteichef",1);
position KGB("KGB-Chef",2);
position outer("Aussenminister",2);
position defense("Verteidigungsminister",2);
position ideals("Ideologie",3);
position industry("Industrie",3);
position sports("Sport und Gesundheit",3);
position agrar("Landwirtschaft",3);

#endif // POSITION_H
