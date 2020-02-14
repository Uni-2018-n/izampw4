#ifndef CARD_HPP
#include "Card.hpp"
#define CARD_HPP
#endif

class Holding:public BlackCard{
protected:
  int IsRevealed;
  int harvest;

public:
  Holding(string nam, holdings type);
};
