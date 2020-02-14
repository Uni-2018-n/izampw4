#ifndef CARD_HPP
#include "Card.hpp"
#define CARD_HPP
#endif


class Personalities:public BlackCard{
protected:
  bool IsRevealed;
  int attack;
  int defense;
  int honor;

public:
  Personalities(string nam, personalities type);
};
