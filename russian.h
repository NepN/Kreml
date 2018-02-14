#ifndef RUSSIAN_H
#define RUSSIAN_H

class russian {
  private:
    string name;
    int birth;
    int health;
    int stress;
    bool state;
  public:
    russian(string n, int b, int h=0) {
      name = n;
      birth = b;
      health = h;
      stress = 0;
      state = false;
    }
    
    string getname() {
      return name;
    }
    int getage() {
      return (realage()+stress);
    }
    int realage() {
      return (1951-birth); 
    }
}

#endif // RUSSIAN_H