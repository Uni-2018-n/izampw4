#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_


#include "givenFiles/DeckBuilder.hpp"


class Player{
private:
  list<GreenCard*>* fateDeck;
  list<BlackCard*>* dynastyDeck;
  list<BlackCard*>* provinces;
  int numofprov;
public:
  Player(DeckBuilder* deck);
  ~Player();
  void print_decks();
};


#endif
