#include "Player.hpp"
#include <iostream>
#include "givenFiles/DeckBuilder.hpp"

fateDeck::fateDeck(){
  DeckBuilder* deck;
  deck = new DeckBuilder();
  list<GreenCard*>* fatedeck=deck->createFateDeck();
  deck->deckShuffler(fatedeck);

}

fateDeck::~fateDeck(){
  cout<<"destructor for fateDeck"<<endl;
}

void fateDeck::printDeck(){
  list<GreenCard *>::iterator it;
  for(it = fatedeck->begin(); it != fatedeck->end(); it++)
  cout << (*it)->getname() << endl;
}
