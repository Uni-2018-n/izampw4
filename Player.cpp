#include "Player.hpp"

Player::Player(DeckBuilder* deck){
  fateDeck = deck->createFateDeck();
  deck->deckShuffler(fateDeck);
  dynastyDeck = deck->createDynastyDeck();
  deck->deckShuffler(dynastyDeck);
  for(int i=0;i<4;i++){
    provinces->push_back(dynastyDeck->front());
    dynastyDeck->pop_front();
  }
  numofprov=4;
  cout << "Constructor Player" << endl;
}

Player::~Player(){
  cout << "Destructor Player" << endl;
}

void Player::print_decks(){
  list<GreenCard *>::iterator it;
  cout<<"######### NOW PRINTING FATE DECK ##########"<<endl;
  for(it = fateDeck->begin(); it != fateDeck->end(); it++)
  cout << (*it)->getname() << endl;
  cout<<"######### NOW PRINTING DYNASTY DECK #########"<<endl;
  list<BlackCard *>::iterator it2;
  for(it2 = dynastyDeck->begin(); it2 != dynastyDeck->end(); it2++)
  cout << (*it2)->getname() << endl;
}
