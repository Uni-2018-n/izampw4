#ifndef _HOLDING_HPP_
#define _HOLDING_HPP_

#ifndef _CARD_HPP_
#include "Card.hpp"
#endif

class Holding:public BlackCard{
private:
  int harvestValue;
  Holding* upperHolding;
  Holding* subHolding;
public:
  Holding(string nam, holdings type);
  int getHarvestValue();
  string getSubcategory();
  int hasUpperHolding();
  int hasSubHolding();
  void printStats();
};

#endif
