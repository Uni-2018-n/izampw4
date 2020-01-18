class Card{
  Card();
  string name;
  int cost;
  bool IsTapped;
};

class Black:public Card{
  Black();
  bool IsRevealed;
  int attack;
  int defense;
  int honor;
};

class Personality:public Black{
  Personality();


};

class Holding:public Black{
  Holdin();

};

class Stronghold:public Black{
  Stronghold();
  int honor;
  int money;
  int InitialDefense;
}
