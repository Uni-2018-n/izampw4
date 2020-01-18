#include<iostream>
#include"Card.hpp"
using namespace std;

 public Card::Card(){
  name="KOSTANTINOS";
  int cost=0;
  bool IsTapped=false;
}

public Black::Black():Card(){
  IsRevealed=false;
  attack=0;
  defense=0;
  honor=0;
}

public Stronghold::Stronghold():Card(){
  honor=0;
  money=69;
  InitialDefense=0;
}
