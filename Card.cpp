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

Black::Black(string nam, int cos):
Card(nam, cos){
  IsRevealed=false;
  attack=0;
  defense=0;
  honor=0;
}

Holding::Holding(string nam, int cos):
Black(nam, cos){

}

// Stronghold::Stronghold():
// Card(){
//   honor=0;
//   money=69;
//   InitialDefense=0;
// }
