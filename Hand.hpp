#ifndef _HAND_HPP_
#define _HAND_HPP_

#include "givenFiles/DeckBuilder.hpp"

class Hand{//TODO must hold 1-6 cards
private:
  list<Follower*>* Followers;
  list<Item*>* Items;
  list<Personality*>* Personalities;
  list<Holding*>* Holdings;
public:
  Hand(list<GreenCard*>* fateDeck);
  bool addToHand(GreenCard* new_card);
  bool addToHand(BlackCard* new_card);
  int currPl();
  void print();
  GreenCard* getCardFromIndex(int cardIndex);
};
#endif
//flex
