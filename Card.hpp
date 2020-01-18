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
