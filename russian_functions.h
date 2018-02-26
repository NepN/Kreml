class russian
{
  public:

  // Alter und Stress
    int getage() 
      { return (realage()+stress); }
    int realage() 
      { return (1951-birth); }
    void addstress(int a) 
      { stress += a; }

 // Zustände
    place* getstate() 
      { return state; }
    void setstate(state* val) 
      { state = val; } 
    bool getcure() 
      { return cure; }
    void setcure(bool val) 
      { cure = val; }
     bool spy() {
      return suspicious;
    }
    void suspicion(bool a) {
      suspisious = a;
    }


  // Einflüsse
    player* getplayer()
      { return influencer;
    void newinfluencer(player* raiser, int o) {
      if (oinfluence<o) {
        influencer = raiser;
        oinfluence = o;
      } else {
        cout << "Ihr Einfluss reicht nicht aus." << endl;
    }


};
