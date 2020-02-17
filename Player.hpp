#include <list>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <ctime>
#include <cstdlib>
#include "Card.hpp"
#include "givenFiles/DeckBuilder.hpp"

//fateDeck == class . fatedeck==Deck
//createfatedeck by constructor
class fateDeck{
public:
  fateDeck();
  ~fateDeck();
	list<GreenCard*>* fatedeck;
  void printfDeck();
};


//dynastyDeck == class , dynastydeck==deck
class dynastyDeck{
public:
  dynastyDeck();
  ~dynastyDeck();
  list<BlackCard*>* dynastydeck;
  void printdDeck();
};
