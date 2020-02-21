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
  list<Personality*>* defendingCards;//prepei na gemizoume auti ti lista
  Provinces(BlackCard& baseCard, Stronghold& currStronghold);
  void print();
  int getHonour();
  int getDefense();
  int getHarvest();
};

#endif
