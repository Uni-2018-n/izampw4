#ifndef CARD_HPP
#include "Card.hpp"
#define CARD_HPP
#endif

class Item:public GreenCard{
private:
  int durability;
public:
  Item(string nam,items type);
  int getDurability();
};
