#include "Follower.hpp"

Follower::Follower(string nam, followers type){
  name = nam;
  category="follower";
  isTapped = false;
  if(type== FOOTSOLDIER){
    cost= 0;
    attackBonus= 2;
    defenceBonus = 0;
    minimumHonour = 1;
    effectBonus = 1;
    effectCost = 2;
  }else if(type== ARCHER){
    cost= 0;
    attackBonus= 0;
    defenceBonus = 2;
    minimumHonour = 1;
    effectBonus = 1;
    effectCost = 2;
  }else if(type== SIEGER){
    cost= 5;
    attackBonus= 3;
    defenceBonus = 3;
    minimumHonour = 2;
    effectBonus = 2;
    effectCost = 3;
  }else if(type== CAVALRY){
    cost= 3;
    attackBonus= 4;
    defenceBonus = 2;
    minimumHonour = 3;
    effectBonus = 3;
    effectCost = 4;
  }else if(type== NAVAL){
    cost= 3;
    attackBonus= 2;
    defenceBonus = 4;
    minimumHonour = 3;
    effectBonus = 3;
    effectCost = 4;
  }else if(type== BUSHIDO){
    cost= 8;
    attackBonus= 8;
    defenceBonus = 8;
    minimumHonour = 6;
    effectBonus = 3;
    effectCost = 8;
  }
}
