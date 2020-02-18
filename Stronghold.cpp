#include "Stronghold.hpp"

Stronghold::Stronghold(){
  cout<<" Stronghold created"<< endl;
};

void Stronghold::print(){
cout << "(honour: " << honour << ", defense: " << defense << ", harvest: " << harvest << ")" << endl;
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
