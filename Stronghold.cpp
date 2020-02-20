#include "Stronghold.hpp"

Stronghold::Stronghold(){

}

void Stronghold::print(){
cout << "(money :" << money << "honour: " << honour << ", defense: " << defense << ", harvest: " << harvest << ")" << endl;
}

int Stronghold::getHonour(){
  return honour;
}

int Stronghold::getDefense(){
  return defense;
}

int Stronghold::getHarvest(){
  return harvest;
}

int Stronghold::getMoney(){
  return money;
}
