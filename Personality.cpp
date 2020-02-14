#include "Personality.hpp"

Personality::Personality(string nam, personalities type){
  name = nam;
  isTapped = false;
  IsRevealed = false;
  if(type == ATTACKER){
    cost=5;
    attack=3;
    defense=2;
    honor=2;
  }
  else if (type==DEFENDER){
    cost=5;
    attack=2;
    defense=3;
    honor=2;
  }
  else if (type==SHOGUN){
    cost=15;
    attack=10;
    defense=5;
    honor=8;
  }
  else if (type==CHANCELLOR){
    cost=15;
    attack=5;
    defense=10;
    honor=8;
  }
  else if (type==CHAMPION){
    cost=30;
    attack=20;
    defense=20;
    honor=12;
  }
}
