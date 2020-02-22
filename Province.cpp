#include "Province.hpp"

Provinces::Provinces(BlackCard& baseCard, Stronghold& currStronghold){
  //copy basecard data(a bit useless but w/e)
  category = baseCard.getCategory();
  name = baseCard.getName();
  cost = baseCard.getCost();
  isTapped = baseCard.getIsTapped();
  IsRevealed = baseCard.getIsRevealed();

  //copy Stronghold data(usefull AF)
  honour = currStronghold.getHonour();
  defense = currStronghold.getDefense();
  harvest = currStronghold.getHarvest();
  defendingCards= new list<Personality*>();
}

void Provinces::print(){
  cout << getName() << "(honour: " << honour << ", defense: " << defense << ", harvest: " << harvest << ")  |  ";
}

int Provinces::getHonour(){
  return honour;
}

int Provinces::getDefense(){
  return defense;
}

int Provinces::getHarvest(){
  return harvest;
}

list<Personality*>* Provinces::getDefendingCards(){
  return defendingCards;
}
