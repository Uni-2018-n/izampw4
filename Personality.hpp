#ifndef CARD_HPP
#include "Card.hpp"
#define CARD_HPP
#endif


class Personality:public BlackCard{
private:
  int attack;
  int defense;
  int honor;
  bool isDead;
  GreenCard* possibleGreen;
public:
  Personality(string nam, personalities type);
  int getAttack();
  int getDefense();
  int getHonor();
  bool getIsDead();
};
