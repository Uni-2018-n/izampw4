
#ifndef _STRONGHOLD_HPP_
#define _STRONGHOLD_HPP_
#include "givenFiles/DeckBuilder.hpp"

class Stronghold:public BlackCard{
private:
  int honour=5;
  int defense=5;
  int harvest=5;
public:
  Stronghold();
  void print();
  int getHonour();
  int getDefense();
  int getHarvest();
};

#endif
