#include "Card.hpp"
//////////////////////////////////////////////////CARD
Card::Card(){

}

void Card::setIsTapped(bool a){
  isTapped=a;
}

string Card::getCategory(){
  return category;
}

string Card::getSubCategory(){
  return subcategory;
}

string Card::getName(){
  return name;
}

int Card::getCost(){
  return cost;
}

bool Card::getIsTapped(){
  return isTapped;
}

//////////////////////////////////////////////////GREENCARD
GreenCard::GreenCard(){

}

int GreenCard::getAttackBonus(){
  return attackBonus;
}
int GreenCard::getDefenseBonus(){
  return defenceBonus;
}
int GreenCard::getMinimumHonour(){
  return minimumHonour;
}
int GreenCard::getEffectBonus(){
  return effectBonus;
}
int GreenCard::getEffectCost(){
  return effectCost;
}
string GreenCard::getCardText(){
  return cardText;
}

//////////////////////////////////////////////////BLACKCARD
BlackCard::BlackCard(){

}

void BlackCard::setIsRevealed(bool a){
  IsRevealed=a;
}

bool BlackCard::getIsRevealed(){
  return IsRevealed;
}
