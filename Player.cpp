#include "Player.hpp"

Player::Player(DeckBuilder& deck){
  honour = a.getHonour();
  fateDeck = deck.createFateDeck();
  deck.deckShuffler(fateDeck);
  dynastyDeck = deck.createDynastyDeck();
  deck.deckShuffler(dynastyDeck);
  provinces = new list<Provinces *>();
  for(int i=0;i<4;i++){
    provinces->push_back(new Provinces(*(dynastyDeck->front()), a));
    dynastyDeck->pop_front();
  }

  numOfProv=4;
  currHand = new Hand(fateDeck);
  cout << "Constructor Player" << endl;
}

Player::~Player(){
  cout << "Destructor Player" << endl;
}

void Player::printDecks(){
  cout<<"######### NOW PRINTING FATE DECK ##########"<<endl;
  {
    list<GreenCard *>::iterator it;
    for(it = fateDeck->begin(); it != fateDeck->end(); it++)
      cout << (*it)->getName() << endl;
  }
  cout<<"######### NOW PRINTING DYNASTY DECK #########"<<endl;
  {
    list<BlackCard *>::iterator it;
    for(it = dynastyDeck->begin(); it != dynastyDeck->end(); it++)
      cout << (*it)->getName() << endl;
  }
}

void Player::printCurrState(){
  cout << "Stronghold: ";
  a.print();

  cout << "Provinces: " << numOfProv << endl;
  {
    list<Provinces *>::iterator it;
    for(it = provinces->begin(); it != provinces->end(); it++)
      (*it)->print();
  }
  cout << endl;

  cout << "Curr Hand: " << endl;
  currHand->print();
}

void Player::untapEverything(){
  list<Provinces *>::iterator it;
  for(it = provinces->begin(); it != provinces->end(); it++)
    (*it)->setIsRevealed(false);
}
