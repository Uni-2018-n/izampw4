#include "Hand.hpp"

Hand::Hand(list<GreenCard*>* fateDeck){
  Followers= new list<Follower *>();
  Items= new list<Item *>();

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

void Hand::print(){
  int count=0;
  {//loop gia oles tis listes ektyponontas mono ta onomata gia twra
    list<Follower *>::iterator it;
    for(it = Followers->begin(); it != Followers->end(); it++)
      cout << "<"<<count++ <<">:" << (*it)->getName() <<
      "(cost: " << (*it)->getCost() << ", " <<
      "attackBonus: " << (*it)->getAttackBonus() << ", " <<
      "defenceBonus: " << (*it)->getDefenseBonus() << ", " <<
      "minimumHonour: " << (*it)->getMinimumHonour() << ", " <<
      "effectBonus: " << (*it)->getEffectBonus() << ", " <<
      "effectCost: " << (*it)->getEffectCost() << "), " << endl;
  }

  {
    list<Item *>::iterator it;
    for(it = Items->begin(); it != Items->end(); it++)
      cout << "<"<<count++ <<">:" << (*it)->getName() <<
      "(cost: " << (*it)->getCost() << ", " <<
      "attackBonus: " << (*it)->getAttackBonus() << ", " <<
      "defenceBonus: " << (*it)->getDefenseBonus() << ", " <<
      "minimumHonour: " << (*it)->getMinimumHonour() << ", " <<
      "effectBonus: " << (*it)->getEffectBonus() << ", " <<
      "effectCost: " << (*it)->getEffectCost() << ", " <<
      "durability: " << (*it)->getDurability()<< "), " << endl;
  }
  cout << endl;
}

int Hand::currPl(){
  int c =0;
  {
  list<Follower *>::iterator it;
  for(it = Followers->begin(); it != Followers->end(); it++)
    c++;
  }

  {
  list<Item *>::iterator it;
  for(it = Items->begin(); it != Items->end(); it++)
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

void Hand::removeCard(int cardIndex){
  int count=0;
  {
    list<Follower*>::iterator it;
    for(it= Followers->begin(); it != Followers->end(); it++){
      if(cardIndex == count){
        Followers->erase(it);
        return;
      }
      count++;
    }
  }

  {
    list<Item*>::iterator it;
    for(it=Items->begin(); it != Items->end(); it++){
      if(cardIndex == count){
        Items->erase(it);
        return;
      }
      count++;
    }
  }
}
