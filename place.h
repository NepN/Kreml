#ifndef PLACE_H
#define PLACE_H

class place {
  private:
    string name;
    
  public:
    place(string n) {
      name = n;
    }
    
    string getname() {
      return name;
    }
};

place cure("Sanatorium");
place city("Stadt");
place sibiria("Sibirien");
place dead("Friedhof");

#endif // PLACE_H