#include "Holding.hpp"

Holding::Holding(string nam,holdings type){
  name = nam;
  category="holding";
  isTapped = false;
  IsRevealed = false;
  if(type==SOLO){
    cost=2;
    harvestValue=2;
    subcategory="SOLO";
  }
  else if(type == PLAIN){
    cost=2;
    harvestValue=2;
    subcategory="PLAIN";
  }
  else if(type==FARMS){
    cost=3;
    harvestValue=4;
    subcategory="FARMS";
  }
  else if (type==MINE){
    cost=5;
    harvestValue=3;
    subcategory="MINE";
  }
  else if (type==GOLD_MINE){
    cost=7;
    harvestValue=3;
    subcategory="GOLD_MINE";
  }
  else if(type==CRYSTAL_MINE){
    cost=12;
    harvestValue=6;
    subcategory="CRYSTAL_MINE";
  }
}

int Holding::getHarvestValue(){
  return harvestValue;
}

string Holding::getSubcategory(){
  return subcategory;
}

int Holding::hasUpperHolding(){
  if((upperHolding)!=NULL){
    return 1;
  }
  else{
    return 0;
  }
}

int Holding::hasSubHolding(){
  if((upperHolding)!=NULL){
    return 1;
  }
  else{
    return 0;
  }
}
