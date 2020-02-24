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
  list<Personality*>* topOfProvincePersonality;
  list<Holding*>* topOfProvinceHolding;

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
  void printProvinces();
public:
  Player(DeckBuilder& deck);
  ~Player();
  bool operator <(const Player & playerObj) const{
    return honour < playerObj.honour;
  }
  void printDecks();

  //top of provinces
  bool fillTopOfProvince(BlackCard* card);
  int getTopOfProvinceCount();
  void printTopOfProvince();

  //Starter Phase
  void untapEverything();
  void drawFateCard();
  void revealProvinces();
  void printCurrState();
  //Equip Phase
  void printOptions();//to print diathesimes kartes kai strato
  int getCountOfPlayedPersonalityCards();
  void equipCardToArmy(int cardIndex, int armyIndex);
  int getCurrHandPl();
  void removeHandCard(int cardIndex);
  //Battle Phase
  list<Personality*>* getPlayedPersonalityCards();
  void printOptionsByEnemys();
  int getCountOfProvinces();
  list<Provinces*>* getProvinces();
  void destroyProvince(int prov);
  void destroyCards(Provinces* prov);//tha sigkrino ti lista played cards me ti lista attackes cards kai an einai idies tha kano pop
  //Chains
  int findMine();//tha vriskei mono mines pou den exoun upperholding
  int findGoldMineWithoutUpper();
  int findGoldMineWithoutSub();
  int findCrystalMine();//tha vriskei crystal miens xoris subholding
  //economyPhase
  void printBuyingOptionsBlack();
  list<Holding*>* getTopOfProvinceHolding();
  list<Personality*>* getTopOfProvincePersonality();
  void printBuyingOptionsGreen();
  void increaseMoney(int a);
  int getMoney(){
    return money;
  }
  void setMoney(int a){
    money = a;
  }

  list<Holding*>* getPlayedHoldingCards(){
    return playedHoldingCards;
  }
};

#endif
//TODO remove code from hpp
