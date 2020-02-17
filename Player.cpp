#include "Player.hpp"
#include <iostream>
#include <list>
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

void fateDeck::printfDeck(){
  list<GreenCard *>::iterator it;
  for(it = fatedeck->begin(); it != fatedeck->end(); it++)
  cout << (*it)->getname() << endl;
}

void dynastyDeck::dynastyDeck(){
  DeckBuilder* deck;
  deck = new DeckBuilder();
  list<BlackCard*>* dynastyDeck=deck->createDynastyDeck();
  deck->deckShuffler(dynastyDeck);
}

dynastyDeck::~dynastyDeck(){
  cout<<"destructor for dynasty"<<endl;
};

void dynastyDeck::printdDeck(){
  list<BlackCard *>::iterator it2;
	 for(it2 = dynastydeck->begin(); it2 != dynastydeck->end(); it2++)
	 cout << (*it2)->getname() << endl;
}
