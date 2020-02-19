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

  int money;//Isos na min xreiazete
  int honour;

  void printHand();
  void printArmy();
public:
  Player(DeckBuilder& deck);
  ~Player();
  bool operator <(const Player & playerObj) const{
    return honour < playerObj.honour;
  }
  void printDecks();
  //Starter Phase
  void untapEverything();//fix this
  void drawFateCard();
  void revealProvinces();
  void printCurrState();
  //Equip Phase
  void printOptions();//to print diathesimes kartes kai strato
  int getCountOfPlayedPersonalityCards();
};

#endif
