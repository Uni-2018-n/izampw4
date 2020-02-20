#include "Hand.hpp"

Hand::Hand(list<GreenCard*>* fateDeck){
  // GreenCard* temp;
  Followers= new list<Follower *>();
  Items= new list<Item *>();
  Personalities = new list<Personality *>();
  Holdings= new list<Holding *>();

  for(int i=0;i<4;i++){//pros8ese 4 arxikes kartes sto xeri
    if(addToHand(fateDeck->front())){
      fateDeck->pop_front();
    }
  }
}

bool Hand::addToHand(GreenCard* new_card){
  if(new_card->getCategory() == "follower"){
    if(currPl() <6){
      Followers->push_back((Follower*)new_card);
      return true;
    }else{
      return false;
    }
  }else if(new_card->getCategory() == "item"){
    if(currPl() <6){
      Items->push_back((Item*)new_card);
      return true;
    }else{
      return false;
    }
  }
  return false;
}

bool Hand::addToHand(BlackCard* new_card){
  if(new_card->getCategory() == "personality"){
    if(currPl() <6){
      Personalities->push_back((Personality*)new_card);
      return true;
    }else{
      return false;
    }
  }else if(new_card->getCategory() == "holding"){
    if(currPl() <6){
      Holdings->push_back((Holding*)new_card);
      return true;
    }else{
      return false;
    }
  }
  return false;
}

void Hand::print(){
  int count=0;
  {//loop gia oles tis listes ektyponontas mono ta onomata gia twra
  list<Follower *>::iterator it;
  for(it = Followers->begin(); it != Followers->end(); it++)
  cout <<count++<<":" << (*it)->getName() << "(), ";
  }

  {
  list<Item *>::iterator it;
  for(it = Items->begin(); it != Items->end(); it++)
  cout <<count++<<":"<< (*it)->getName() << "(durability: " << (*it)->getDurability() << "), ";
  }

  {
  list<Personality *>::iterator it;
  for(it = Personalities->begin(); it != Personalities->end(); it++)
  cout << count++ << ":" << (*it)->getName() << "(attack: " << (*it)->getAttack() << ", defense: "<< (*it)->getDefense() << ", honor: " << (*it)->getHonor() << "), ";
  }

  {
  list<Holding *>::iterator it;
  for(it = Holdings->begin(); it != Holdings->end(); it++)
  cout << count++ << ":" << (*it)->getName() << "(harvestValue: " << (*it)->getHarvestValue() << "), ";
  }

  cout << endl;
}

int Hand::currPl(){
  int c =0;
  {//loop gia oles tis listes ektyponontas mono ta onomata gia twra
  list<Follower *>::iterator it;
  for(it = Followers->begin(); it != Followers->end(); it++)
    c++;
  }

  {
  list<Item *>::iterator it;
  for(it = Items->begin(); it != Items->end(); it++)
    c++;
  }

  {
  list<Personality *>::iterator it;
  for(it = Personalities->begin(); it != Personalities->end(); it++)
    c++;
  }

  {
  list<Holding *>::iterator it;
  for(it = Holdings->begin(); it != Holdings->end(); it++)
    c++;
  }
  return c;
}

GreenCard* Hand::getCardFromIndex(int cardIndex){
  int count=0;
  {
    list<Follower*>::iterator it;
    for(it= Followers->begin(); it != Followers->end(); it++){
      if(cardIndex == count){
        return (*it);
      }
      count++;
    }
  }

  {
    list<Item*>::iterator it;
    for(it=Items->begin(); it != Items->end(); it++){
      if(cardIndex == count){
        return (*it);
      }
      count++;
    }
  }
  return NULL;
}
