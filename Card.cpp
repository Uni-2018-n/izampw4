#include "Card.hpp"
#include<iostream>
Card::Card(string nam, int cos, bool iTap):
name(nam), cost(cos), isTapped(iTap){
}

////////////////////GreenCard
GreenCard::GreenCard(string nam, int cos, int attacB, int defencB, int minH, int effecB, int effecC, string cardT):
Card(nam, cos, false){
  attackBonus= attacB;
  defenceBonus= defencB;
  minimumHonour= minH;
  effectBonus= effecB;
  effectCost= effecC;
  cardText= cardT;
}


////////////////////Follower
Follower::Follower(string nam, int cos, int attacB, int defencB, int minH, int effecB, int effecC, string cardT):
GreenCard(nam, cos, attacB, defencB, minH, effecB, effecC, cardT){

}

////////////////////FootSoldier
FootSoldier::FootSoldier(string nam, string cardT):
Follower(nam, 0, 2, 0, 1, 1, 2, cardT){

}

////////////////////Archer
Archer::Archer(string nam, string cardT):
Follower(nam, 0, 0, 2, 1, 1, 2, cardT){

}

////////////////////Cavalry
Cavalry::Cavalry(string nam, string cardT):
Follower(nam, 3, 4, 2, 3, 3, 4, cardT){

}

////////////////////Bushido
Bushido::Bushido(string nam, string cardT):
Follower(nam, 8, 8, 8, 6, 3, 8, cardT){

}

////////////////////Sieger
Sieger::Sieger(string nam, string cardT):
Follower(nam, 5, 3, 3, 2, 2, 3, cardT){

}

////////////////////Naval
Naval::Naval(string nam, string cardT):
Follower(nam, 3, 2, 4, 3, 3, 4, cardT){

}

////////////////////Item






////////////////////
BlackCard::BlackCard(string nam, int cos):
Card(nam, cos, false){
  IsRevealed=false;
  cost=0;
}

Personalities::Personalities():
BlackCard(){

  attack=0;
  defense=0;
  honor=0;
  isDead=false;
}

Holding::Holding(string nam, int cos):
BlackCard(){
  harvest=0;
}

Stronghold::Stronghold(string nam, int cos):
BlackCard(){
  honor=0;
  money=69;
  InitialDefense=0;
}

Attacker::Attacker():Personalities(){
  cost=5;
  attack=3;
  defense=2;
  honor=2;
  isDead=false;
}

Defender::Defender():Personalities(){
  cost=5;
  attack=2;
  defense=3;
  honor=2;
  isDead=false;
}

Shogun::Shogun():Personalities(){
  cost=15;
  attack=10;
  defense=5;
  honor=8;
  isDead=false;
}

Chancellor::Chancellor():Personalities(){
  cost=15;
  attack=5;
  defense=10;
  honor=8;
  isDead=false;
}

Champion::Champion():Personalities(){
  cost=30;
  attack=20;
  defense=20;
  honor=12;
  isDead=false;
}

Solo::Solo():Holding(){
  cost=2;
  harvest=2;
}

Plain::Plain():Holding(){
  cost=2;
  harvest=2;
}

Farms::Farms():Holding(){
  cost=3;
  harvest=4;
}

Mine::Mine():Holding(){
  cost=5;
  harvest=3;
}

GoldMine::GoldMine():Holding(){
  cost=7;
  harvest=5;
}

CrystalMine::CrystalMine():Holding(){
  cost=12;
  harvest=6;
}
