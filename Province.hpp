#ifndef _PROVINCE_HPP_
#define _PROVINCE_HPP_

#include "givenFiles/DeckBuilder.hpp"
#include "Stronghold.hpp"

class Provinces:public BlackCard{
private:
  int honour;
  int defense;
  int harvest;
public:
  Provinces(BlackCard& baseCard, Stronghold& currStronghold);
  void print();
};

#endif