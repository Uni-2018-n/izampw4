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
