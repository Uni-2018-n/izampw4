#include "Hand.hpp"

Hand::Hand(list<GreenCard*>* fateDeck){
  Followers= new list<GreenCard *>();
  Items= new list<GreenCard *>();
  Personalities = new list<BlackCard *>();
  Holdings= new list<BlackCard *>();

  add_to_hand(fateDeck->front());
  fateDeck->pop_front();
  add_to_hand(fateDeck->front());
  fateDeck->pop_front();
  add_to_hand(fateDeck->front());
  fateDeck->pop_front();
  add_to_hand(fateDeck->front());
  fateDeck->pop_front();
}

void Hand::add_to_hand(GreenCard* new_card){
  if(new_card->getCategory() == "follower"){
    Followers->push_back(new_card);
  }else{
    Items->push_back(new_card);
  }
}

void Hand::add_to_hand(BlackCard* new_card){
  if(new_card->getCategory() == "holding"){
    Holdings->push_back(new_card);
  }else{
    Personalities->push_back(new_card);
  }
}
