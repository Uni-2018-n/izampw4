#include "Player.hpp"

Player::Player(DeckBuilder* deck){
  fateDeck = deck->createFateDeck();
  deck->deckShuffler(fateDeck);
  dynastyDeck = deck->createDynastyDeck();
  deck->deckShuffler(dynastyDeck);
  cout << "Constructor Player" << endl;
}

Player::~Player(){
  cout << "Destructor Player" << endl;
}

void Player::print_decks(){
  list<GreenCard *>::iterator it;
  for(it = fateDeck->begin(); it != fateDeck->end(); it++)
  cout << (*it)->getname() << endl;

  list<BlackCard *>::iterator it2;
  for(it2 = dynastyDeck->begin(); it2 != dynastyDeck->end(); it2++)
  cout << (*it2)->getname() << endl;
}
