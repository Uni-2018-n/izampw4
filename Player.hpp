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

  list<GreenCard*>* playedFollowerCards;
  list<GreenCard*>* playedItemCards;
  list<BlackCard*>* playedPersonalityCards;
  list<BlackCard*>* playedHoldingCards;


  int honour;
public:
  Player(DeckBuilder& deck);
  ~Player();
  bool operator <(const Player & playerObj) const{
    return honour < playerObj.honour;
  }
  void printDecks();
  void untapEverything();//fix this
  void revealProvinces();
  void printCurrState();
  void drawFateCard();
};

#endif
