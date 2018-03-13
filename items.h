#ifndef ITEMS_H
#define ITEMS_H

class items { // mother class for named objects. share functions like getname()
  private:
    string name;
  public:
    items(string n) {
      name = n;
    }
    
    string getname() {
      return name;
    }
};

#endif // ITEMS_H