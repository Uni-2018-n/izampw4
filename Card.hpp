#ifndef CARD_HPP
#define CARD_HPP

#include <iostream>
using namespace std;

enum items{KATANA, SPEAR, BOW, NINJATO, WAKIZASHI};
enum followers {FOOTSOLDIER, ARCHER, SIEGER, CAVALRY, NAVAL, BUSHIDO};
enum personalities {ATTACKER, DEFENDER, SHOGUN, CHANCELLOR, CHAMPION};
enum holdings {PLAIN, MINE, GOLD_MINE, CRYSTAL_MINE, FARMS, SOLO, STRONGHOLD};

class Card{
protected:
  string category;
  string subcategory;
  string name;
  int cost;
  bool isTapped;
public:
  Card();
  void setIsTapped(bool a);
  string getCategory();
  string getName();
  int getCost();
  bool getIsTapped();
};

class GreenCard:public Card{
protected:
  int attackBonus;
  int defenceBonus;
  int minimumHonour;

  int effectBonus;
  int effectCost;

  string cardText;
public:
  GreenCard();
  int getAttackBonus();
  int getDefenseBonus();
  int getMinimumHonour();
  int getEffectBonus();
  int getEffectCost();
  string getCardText();
};


class BlackCard:public Card{
protected:
  bool IsRevealed;
public:
  BlackCard();
  void setIsRevealed(bool a);
  bool getIsRevealed();
};

#endif
