#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include "givenFiles/DeckBuilder.hpp"
#include "Hand.hpp"
#include "Stronghold.hpp"

class Player{
private:
  list<GreenCard*>* fateDeck;
  list<BlackCard*>* dynastyDeck;
  list<BlackCard*>* provinces;
  Stronghold a;
  Hand* currHand;
  int numOfProv;
public:
  Player(DeckBuilder& deck);
  ~Player();
  void printDecks();
  void untapEverything();
  void printCurrState();
};

#endif
