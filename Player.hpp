#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_


#include "givenFiles/DeckBuilder.hpp"


class Player{
private:
  list<GreenCard*>* fateDeck;
  list<BlackCard*>* dynastyDeck;
public:
  Player(DeckBuilder* deck);
  ~Player();
  void print_decks();
};


#endif
