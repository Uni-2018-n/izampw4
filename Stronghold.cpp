#include "Stronghold.hpp"

Stronghold::Stronghold(){
  cout<<" Stronghold created"<< endl;
};

void Stronghold::print(){
  cout << "Honour: " << honour << endl;
  cout << "Defense: " << defense << endl;
  cout << "Harvest: " << harvest << endl;
}
