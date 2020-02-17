#ifndef CARD_HPP

#include <iostream>
using namespace std;

enum items{KATANA, SPEAR, BOW, NINJATO, WAKIZASHI};
enum followers {FOOTSOLDIER, ARCHER, SIEGER, CAVALRY, NAVAL, BUSHIDO};
enum personalities {ATTACKER, DEFENDER, SHOGUN, CHANCELLOR, CHAMPION};
enum holdings {PLAIN, MINE, GOLD_MINE, CRYSTAL_MINE, FARMS, SOLO, STRONGHOLD};

class Card{
protected:
  string category;
  string name;
  int cost;
  bool isTapped;
public:
  Card(){};

  string getname(){
    return name;
  }
  string getCategory(){
    return category;
  }
};

class GreenCard:public Card{
protected:
  int attackBonus;
  int defenceBonus;
  int minimumHonour;

  int effectBonus;
  int effectCost;

  string cardText;//nothing happens here

public:
  GreenCard(){};
};


class BlackCard:public Card{
protected:
  int IsRevealed;

public:
  BlackCard(){};
};

#define CARD_HPP
#endif
