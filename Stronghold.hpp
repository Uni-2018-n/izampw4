
#ifndef _STRONGHOLD_HPP_
#define _STRONGHOLD_HPP_
#include "givenFiles/DeckBuilder.hpp"
class Stronghold:public BlackCard{
public:
  Stronghold();
  void print();
private:
  int honour=5;
  int defense=5;
  int harvest=5;
};
#endif
