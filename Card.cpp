#include<iostream>
using namespace std;
Card::Card(){
  name="KOSTANTINOS";
  int cost=0;
  bool IsTapped=false;
}

Black::Black():Card(){
  IsRevealed=false;
  attack=0;
  defense=0;
  honor=0;
}

Stronghold::Stronghold():Card(){
  honor=0;
  money=69;
  InitialDefense=0;
}
