#ifndef CARD_HPP
#include "Card.hpp"
#define CARD_HPP

//////////////////////////////////////////////////CARD
Card::Card(){

}

void Card::setIsTapped(bool a){
  isTapped=a;
}

string Card::getCategory(){
  return category;
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

//////////////////////////////////////////////////BLACKCARD
BlackCard::BlackCard(){

}

void BlackCard::setIsRevealed(bool a){
  IsRevealed=a;
}

bool BlackCard::getIsRevealed(){
  return IsRevealed;
}

#endif
