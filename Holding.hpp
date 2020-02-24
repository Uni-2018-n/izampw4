#ifndef _HOLDING_HPP_
#define _HOLDING_HPP_

#ifndef _CARD_HPP_
#include "Card.hpp"
#endif

class Holding:public BlackCard{
private:
  int harvestValue;
  int hasUpperHolding;
  int hasSubHolding;
public:
  Holding(string nam, holdings type);
  int getHarvestValue();
  string getSubcategory();
  int getHasUpperHolding();
  void changeUpperHoldingStatus();
  int getHasSubHolding();
  void changeSubHoldingStatus();
  void printStats();
  void printStats(bool a);
  void increaseHarvestValue(int a);
};

#endif
