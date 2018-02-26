#ifndef RUSSIAN_ACTIONS_H
#define RUSSIAN_ACTIONS_H

class russian 
{
  public:

  // Turn 1: Kuren 
  // Turn 3: Säuberungen
    bool askplayer(string n) {
      if ( n == "cure" ) { // umwandeln in switch-case mit hash-funktion (enum) oder ähnliches
        cout << "Soll dieser Charakter in Kur gehen/bleiben?" << endl;
        bool a;
        // cin >> a;
        return a;
      } else if ( n == "purge") {
        cout << "Wollen Sie einen Genossen wegsäubern?" << endl;
        bool a;
        // cin >> a;
        return a;
      } 
    } // templatisieren für verschiedene return-Datentypen (bool, russian*, ...)
    russian* askplayerconcrete(string n) {
      if ( n == "purge" ) {
        cout << "Wen wollen Sie säubern?" << endl;
        russian* purged;
        // cin >> &purged;
        return purged;
      }
    }
    
  // Turn 4: Gesundheitszustand ermitteln 
    // health-values
    int gethealth() return health;
    void healthCheck() {
      // roll W20 dice 
      int w = rand() % 20;
      cout << "W = " << w << endl;
      
      // determine right table and result (result value equals change of health)
      int c;
      if (state) { 
        c = ::work.getH(age(),w); // global vordefiniert
      } else { 
        c = ::cure.getH(age(),w); // global vordefiniert
      }
      // apply change of health to russian's health stat 
      addhealth(c);
    }
  
  // Turn 7: Rehabilitation
    void rehab(russian* ruski) {
      if (ruski->state == &sibiria) { // validate ruski is in sibiria
        // Zulässigkeiten der Auswahl sollten bei Eingabe abgefragt / sichergestellt werden
        // nicht in jeder Funktion
        ruski->state = &plebs;
        stress += 5;
      }
    }
  
  // Turn 8: Oktoberparade
    void parade() {
      int w = rand() % 20 + 1;
      switch (health)
      {
        case 2: 
          stress += 2;
          if (w>=15) {
            // add event to parade-list
          }
          break;
        case 1: 
          stress += 1;
          if (w>=8) {
            // add event to parade-list
          }
          break;
        case 0: 
          // add event to parade-list
        default:
          cout << "Die Parade konnte nicht beendet werden." << endl; 
      }
         
    }
   


}

#endif RUSSIAN_ACTIONS_H