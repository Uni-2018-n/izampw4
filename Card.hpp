#include <iostream>
using namespace std;

class Card{
private:
  string name;
  int cost;
  bool isTapped;
public:
  Card(string nam, int cos);
};

class GreenCard:public Card{
private:
  int attackBonus;
  int defenceBonus;
  int minimumHonour;
  string cardText;
  int effectBonus;
  int effectCost;
  int durability;
public:
  GreenCard(string nam, int cos);

};

class Follower:public GreenCard{//prosopikh froyra

};

class Item:public Follower{//eksoplismos prosopikothtas

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
