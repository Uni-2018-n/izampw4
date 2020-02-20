#include "Holding.hpp"

Holding::Holding(string nam,holdings type){
  name = nam;
  category="holding";
  isTapped = false;
  IsRevealed = false;
  if(type==SOLO){
    cost=2;
    harvestValue=2;
  }
  else if(type == PLAIN){
    cost=2;
    harvestValue=2;
  }
  else if(type==FARMS){
    cost=3;
    harvestValue=4;
  }
  else if (type==MINE){
    cost=5;
    harvestValue=3;
  }
  else if (type==GOLD_MINE){
    cost=7;
    harvestValue=3;
  }
  else if(type==CRYSTAL_MINE){
    cost=12;
    harvestValue=6;
  }
}

int Holding::getHarvestValue(){
  return harvestValue;
}
