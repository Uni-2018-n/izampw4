#ifndef CARD_HPP
#include "Card.hpp"
#define CARD_HPP
#endif

class Holding:public BlackCard{
protected:
  int harvestValue;
  Holding* upperHolding;
  Holding* subHolding;

public:
  Holding(string nam, holdings type);
};
