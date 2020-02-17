#include "givenFiles/DeckBuilder.hpp"


class Hand{
private:
  list<GreenCard*>* Followers;
  list<GreenCard*>* Items;
  list<BlackCard*>* Personalities;
  list<BlackCard*>* Holdings;
public:
  Hand();
  add_to_hand(GreenCard* new_card);
}
