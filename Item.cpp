#include "Item.hpp"

Item::Item(string nam, items type){
  name = nam;
  category="item";
  isTapped= false;
  if(type == KATANA){
    cost= 0;
    attackBonus=2;
    defenceBonus = 0;
    minimumHonour = 1;
    effectBonus = 1;
    effectCost =2;
    durability = 3;
    subcategory="KATANA";
  }else if(type == SPEAR){
    cost= 0;
    attackBonus=0;
    defenceBonus = 2;
    minimumHonour = 1;
    effectBonus = 1;
    effectCost =2;
    durability = 3;
    subcategory="SPEAR";
  }else if(type == BOW){
    cost= 2;
    attackBonus= 2;
    defenceBonus = 2;
    minimumHonour = 2;
    effectBonus = 3;
    effectCost = 4;
    durability = 5;
    subcategory="BOW";
  }else if(type == NINJATO){
    cost= 4;
    attackBonus= 3;
    defenceBonus = 3;
    minimumHonour = 3;
    effectBonus = 2;
    effectCost = 2;
    durability = 4;
    subcategory="NIJATO";
  }else if(type == WAKIZASHI){
    cost= 8;
    attackBonus= 5;
    defenceBonus = 5;
    minimumHonour = 3;
    effectBonus = 3;
    effectCost = 3;
    durability = 8;
    subcategory="WAKIZASHI";
  }
}

int Item::getDurability(){
  return durability;
}
void Item::setDurability(int a){
  durability=a;
}
