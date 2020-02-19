#include "Hand.hpp"

Hand::Hand(list<GreenCard*>* fateDeck){
  Followers= new list<GreenCard *>();
  Items= new list<GreenCard *>();
  Personalities = new list<BlackCard *>();
  Holdings= new list<BlackCard *>();

  for(int i=0;i<4;i++){//pros8ese 4 arxikes kartes sto xeri
    if(addToHand(fateDeck->front())){
      fateDeck->pop_front();
    }
  }
}

bool Hand::addToHand(GreenCard* new_card){
  if(currPl() <6){
    if(new_card->getCategory() == "follower"){//gia to se pia lista na balei thn karta wste na einai omadopoihmenes
      Followers->push_back(new_card);
    }else{
      Items->push_back(new_card);
    }
    return true;
  }else{
    return false;
  }
}

bool Hand::addToHand(BlackCard* new_card){
  if(currPl() <6){
    if(new_card->getCategory() == "holding"){
      Holdings->push_back(new_card);
    }else{
      Personalities->push_back(new_card);
    }
    return true;
  }else{
    return false;
  }
}

void Hand::print(){
  int count=0;
  {//loop gia oles tis listes ektyponontas mono ta onomata gia twra
  list<GreenCard *>::iterator it;
  for(it = Followers->begin(); it != Followers->end(); it++)
  cout <<count++<<":" << (*it)->getName() << ", ";
  }

  {
  list<GreenCard *>::iterator it;
  for(it = Items->begin(); it != Items->end(); it++)
  cout <<count++<<":"<< (*it)->getName() << ", ";
  }

  {
  list<BlackCard *>::iterator it;
  for(it = Personalities->begin(); it != Personalities->end(); it++)
  cout << count++ << ":" << (*it)->getName() << ", ";
  }

  {
  list<BlackCard *>::iterator it;
  for(it = Holdings->begin(); it != Holdings->end(); it++)
  cout << count++ << ":" << (*it)->getName() << ", ";
  }

  cout << endl;
}

int Hand::currPl(){
  int c =0;
  {//loop gia oles tis listes ektyponontas mono ta onomata gia twra
  list<GreenCard *>::iterator it;
  for(it = Followers->begin(); it != Followers->end(); it++)
    c++;
  }

  {
  list<GreenCard *>::iterator it;
  for(it = Items->begin(); it != Items->end(); it++)
    c++;
  }

  {
  list<BlackCard *>::iterator it;
  for(it = Personalities->begin(); it != Personalities->end(); it++)
    c++;
  }

  {
  list<BlackCard *>::iterator it;
  for(it = Holdings->begin(); it != Holdings->end(); it++)
    c++;
  }
  return c;
}
