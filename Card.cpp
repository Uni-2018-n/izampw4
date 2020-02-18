#ifndef CARD_HPP
#include "Card.hpp"
#define CARD_HPP

//////////////////////////////////////////////////CARD
Card::Card(){

}

string Card::getname(){
  return name;
}

string Card::getCategory(){
  return category;
}

void Card::setIsTapped(bool a){
  isTapped=a;
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

#endif
