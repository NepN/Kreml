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