#ifndef _ITEM_HPP_
#define _ITEM_HPP_

#ifndef _CARD_HPP_
#include "Card.hpp"
#endif

class Item:public GreenCard{
private:
  int durability;
public:
  Item(string nam,items type);
  int getDurability();
  void setDurability(int a);
};

#endif
