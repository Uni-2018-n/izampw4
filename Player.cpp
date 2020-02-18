#include "Player.hpp"

Player::Player(DeckBuilder& deck){
  fateDeck = deck.createFateDeck();
  deck.deckShuffler(fateDeck);
  dynastyDeck = deck.createDynastyDeck();
  deck.deckShuffler(dynastyDeck);
  provinces = new list<BlackCard *>();
  for(int i=0;i<4;i++){
    provinces->push_back(dynastyDeck->front());
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
  list<GreenCard *>::iterator it;
  cout<<"######### NOW PRINTING FATE DECK ##########"<<endl;
  for(it = fateDeck->begin(); it != fateDeck->end(); it++)
  cout << (*it)->getname() << endl;
  cout<<"######### NOW PRINTING DYNASTY DECK #########"<<endl;
  list<BlackCard *>::iterator it2;
  for(it2 = dynastyDeck->begin(); it2 != dynastyDeck->end(); it2++)
  cout << (*it2)->getname() << endl;
}

void Player::printCurrState(){
  cout << "Stronghold: " << endl;
  a.print();

  cout << "Provinces: " << numOfProv << endl;
  list<BlackCard *>::iterator it2;
  for(it2 = provinces->begin(); it2 != provinces->end(); it2++)
  cout << (*it2)->getname() << "     ";
  cout << endl;

  cout << "Curr Hand: " << endl;
  currHand->print();

}

void Player::untapEverything(){
  list<BlackCard *>::iterator it2;
  for(it2 = provinces->begin(); it2 != provinces->end(); it2++)
  (*it2)->setIsRevealed(false);
}
