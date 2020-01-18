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
