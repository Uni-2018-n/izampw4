#include "Hand.hpp"


Hand::add_to_hand(GreenCard* new_card){
  if(new_card->getCategory() == "follower"){
    Followers->push_back(new_card);
  }
}
