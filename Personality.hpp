#ifndef CARD_HPP
#include "Card.hpp"
#define CARD_HPP
#endif


class Personality:public BlackCard{
protected:
  int attack;
  int defense;
  int honor;
  bool isDead;

  GreenCard* possible_green;

public:
  Personality(string nam, personalities type);
};
