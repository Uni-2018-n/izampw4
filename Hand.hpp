#ifndef _HAND_HPP_
#define _HAND_HPP_

#include "givenFiles/DeckBuilder.hpp"


class Hand{
private:
  list<GreenCard*>* Followers;
  list<GreenCard*>* Items;
  list<BlackCard*>* Personalities;
  list<BlackCard*>* Holdings;
public:
  Hand();
  void add_to_hand(GreenCard* new_card);
  void add_to_hand(BlackCard* new_card);
};
#endif
