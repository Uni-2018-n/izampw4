#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include "givenFiles/DeckBuilder.hpp"
#include "Hand.hpp"
#include "Stronghold.hpp"
#include "Province.hpp"

class Player{
private:
  Stronghold a;
  list<GreenCard*>* fateDeck;
  list<BlackCard*>* dynastyDeck;
  list<BlackCard*>* availableDynastyCards;
  list<Provinces*>* provinces;
  int numOfProv;
  Hand* currHand;

  list<GreenCard*>* playedGreenCards;
  list<BlackCard*>* playedBlackCards;

  int honour;
public:
  Player(DeckBuilder& deck);
  ~Player();
  void printDecks();
  void untapEverything();
  void revealProvinces();
  void printCurrState();
  void drawFateCard();
};

#endif
