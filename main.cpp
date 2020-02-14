#include <iostream>
using namespace std;
#include "givenFiles/DeckBuilder.hpp"


int main(){
	DeckBuilder* deck;

	deck = new DeckBuilder();


	list<GreenCard*>* tempG=deck->createFateDeck();

	deck->deckShuffler(tempG);


	list<GreenCard *>::iterator it;
	for(it = tempG->begin(); it != tempG->end(); it++)
	cout << (*it)->getname() << endl;
	cout << endl << endl;
	list<BlackCard*>* tempB=deck->createDynastyDeck();

	deck->deckShuffler(tempB);


	list<BlackCard *>::iterator it2;
	for(it2 = tempB->begin(); it2 != tempB->end(); it2++)
	cout << (*it2)->getname() << endl;
	return 0;
}
