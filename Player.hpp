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

  list<Follower*>* playedFollowerCards;
  list<Item*>* playedItemCards;
  list<Personality*>* playedPersonalityCards;
  list<Holding*>* playedHoldingCards;

  int money;
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
  void untapEverything();
  void drawFateCard();
  void revealProvinces();
  void printCurrState();
  //Equip Phase
  void printOptions();//to print diathesimes kartes kai strato
  int getCountOfPlayedPersonalityCards();
  void equipCardToArmy(int cardIndex, int armyIndex);
};

#endif
