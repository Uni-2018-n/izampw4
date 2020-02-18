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
  int numofprov;
public:
  Player(DeckBuilder& deck);
  ~Player();
  void print_decks();
  void untapEverything();
  void printCurrState();
};

#endif
