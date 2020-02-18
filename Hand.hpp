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
  Hand(list<GreenCard*>* fateDeck);
  void addToHand(GreenCard* new_card);
  void addToHand(BlackCard* new_card);
  void print();
};
#endif
