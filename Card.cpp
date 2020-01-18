#include "Card.hpp"

Card::Card(string nam, int cos):
name(nam), cost(cos){
  isTapped=0;
}

////////////////////GreenCard
GreenCard::GreenCard(string nam, int cos):
Card(nam, cos){
  attackBonus =0;
  defenceBonus=0;
  minimumHonour=0;
  cardText ="random for now";
  effectBonus=0;
  effectCost=0;
  durability=0;
}

Black::Black():public Card(){
  IsRevealed=false;
  attack=0;
  defense=0;
  honor=0;
}

Stronghold::Stronghold():public Card(){
  honor=0;
  money=69;
  InitialDefense=0;
