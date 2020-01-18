
class Card{
  Card();
  string name;
  int cost;
  bool IsTapped;
};

class Black:public Card{
private:
  bool IsRevealed;
  int attack;
  int defense;
  int honor;
public:
  Black(string nam, int cos);
};

class Personality:public Black{
private:

public:
  Personality();
};

class Holding:public Black{
private:

public:
  Holding(string nam, int cos);

};

// class Stronghold:public Black{
// private:
//   int honor;
//   int money;
//   int InitialDefense;
// public:
//   Stronghold();
// };
