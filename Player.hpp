#include "givenFiles/DeckBuilder.hpp"


class Player{
private:
  list<GreenCard*>* fateDeck;
  list<BlackCard*>* dynastyDeck;
public:
  Player(DeckBuilder* deck);
  ~Player();
  void print_decks();
}
