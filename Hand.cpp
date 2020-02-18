#include "Hand.hpp"

Hand::Hand(list<GreenCard*>* fateDeck){
  Followers= new list<GreenCard *>();
  Items= new list<GreenCard *>();
  Personalities = new list<BlackCard *>();
  Holdings= new list<BlackCard *>();

  addToHand(fateDeck->front());
  fateDeck->pop_front();
  addToHand(fateDeck->front());
  fateDeck->pop_front();
  addToHand(fateDeck->front());
  fateDeck->pop_front();
  addToHand(fateDeck->front());
  fateDeck->pop_front();
}

void Hand::addToHand(GreenCard* new_card){
  if(new_card->getCategory() == "follower"){
    Followers->push_back(new_card);
  }else{
    Items->push_back(new_card);
  }
}

void Hand::addToHand(BlackCard* new_card){
  if(new_card->getCategory() == "holding"){
    Holdings->push_back(new_card);
  }else{
    Personalities->push_back(new_card);
  }
}

void Hand::print(){
  list<GreenCard *>::iterator it2;
  for(it2 = Followers->begin(); it2 != Followers->end(); it2++)
  cout << (*it2)->getname() << ", ";
  list<GreenCard *>::iterator it3;
  for(it3 = Items->begin(); it3 != Items->end(); it3++)
  cout << (*it3)->getname() << ", ";

  list<BlackCard *>::iterator it4;
  for(it4 = Personalities->begin(); it4 != Personalities->end(); it4++)
  cout << (*it4)->getname() << ", ";
  list<BlackCard *>::iterator it5;
  for(it5 = Holdings->begin(); it5 != Holdings->end(); it5++)
  cout << (*it5)->getname() << ", ";

  cout << endl;
}
