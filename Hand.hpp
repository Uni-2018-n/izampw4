#ifndef _HAND_HPP_
#define _HAND_HPP_

#include "givenFiles/DeckBuilder.hpp"

class Hand{
private:
  list<Follower*>* Followers;
  list<Item*>* Items;
public:
  Hand(list<GreenCard*>* fateDeck);

  bool addToHand(GreenCard* new_card);

  int currPl();
  void print();
  GreenCard* getCardFromIndex(int cardIndex);
  void removeCard(int cardIndex);
};
#endif
