#include "Player.hpp"

Player::Player(DeckBuilder& deck){
  //setters
  money=a.getMoney();
  honour = a.getHonour();
  fateDeck = deck.createFateDeck();
  deck.deckShuffler(fateDeck);
  dynastyDeck = deck.createDynastyDeck();
  deck.deckShuffler(dynastyDeck);
  playedPersonalityCards = new list<BlackCard*>();
  playedHoldingCards = new list<BlackCard*>();

  playedFollowerCards = new list<GreenCard*>();
  playedItemCards = new list<GreenCard*>();


  //create provinces, push_back a new province with a black card and stronghold as arguments
  provinces = new list<Provinces *>();
  for(int i=0;i<4;i++){
    provinces->push_back(new Provinces(*(dynastyDeck->front()), a));
    dynastyDeck->pop_front();
  }
  numOfProv=4;

  //then create the top-of-provinces-cards(einai unrevealed, arxh ka8e gyroy ginontai revealed oses einai katw)
  //aytes tis kartes mporei o pekths na tis agorasei an 8elei(TODO)
  availableDynastyCards = new list<BlackCard*>();
  for(int i=0;i<4;i++){
    availableDynastyCards->push_back(dynastyDeck->front());
    dynastyDeck->pop_front();
  }

  //to currhand toy paikth, mporei na exei olwn twn eidwn kartes
  //alla twra(before start stadio) exei 4 prasines
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

  cout << "Top of provinces:" << endl;
  {
    list<BlackCard*>::iterator it;//print tis kartes poy einai panw apo tis eparxies
    for(it = availableDynastyCards->begin(); it != availableDynastyCards->end(); it++){
      if((*it)->getIsRevealed() == true){//mono an einai revealed
        cout << (*it)->getName() << "   ";
      }else{
        cout << "(CARD UNREVEALED)" << "    ";//allios rip
      }
    }
    cout << endl;
  }
  cout << "Provinces: " << numOfProv << endl;
  {
    list<Provinces *>::iterator it;//print ta provinces
    for(it = provinces->begin(); it != provinces->end(); it++)
      if((*it)->getIsRevealed() == true)//2.4 1h par teleytaia protash
        (*it)->print();
      else
        cout << "(PROVINCE UNREVEALED)    ";
  }
  cout << endl;

  cout << "Curr Hand: " << endl;
  currHand->print();
}

void Player::printHand(){
  currHand->print();
}

void Player::printArmy(){
  int count=0;
  list<BlackCard*>::iterator it;
  for(it = playedPersonalityCards->begin(); it != playedPersonalityCards->end(); it++){
    cout << count++ << ":" << (*it)->getName() << "   ";
  }
  cout << endl;
}


void Player::untapEverything(){
  {
  list<BlackCard *>::iterator it;
  for(it = playedPersonalityCards->begin(); it != playedPersonalityCards->end(); it++)
    (*it)->setIsTapped(false);
  }
  {
  list<GreenCard *>::iterator it;
  for(it = playedFollowerCards->begin(); it != playedFollowerCards->end(); it++)
    (*it)->setIsTapped(false);
  }

  {
  list<BlackCard *>::iterator it;
  for(it = playedHoldingCards->begin(); it != playedHoldingCards->end(); it++)
    (*it)->setIsTapped(false);
  }
  {
  list<GreenCard *>::iterator it;
  for(it = playedItemCards->begin(); it != playedItemCards->end(); it++)
    (*it)->setIsTapped(false);
  }
}

void Player::revealProvinces(){
  {
  list<BlackCard *>::iterator it;
  for(it = availableDynastyCards->begin(); it != availableDynastyCards->end(); it++)
    (*it)->setIsRevealed(true);
  }

  {
  list<Provinces *>::iterator it;
  for(it = provinces->begin(); it != provinces->end(); it++)
    (*it)->setIsRevealed(true);
  }
}

void Player::drawFateCard(){
  if(currHand->addToHand(fateDeck->front())){
    fateDeck->pop_front();
  }
}

void Player::printOptions(){
  cout<<"Printing Hand : "<<endl;
  printHand();
  cout<<"Printing Army : "<< endl;
  printArmy();

}

int Player::getCountOfPlayedPersonalityCards(){
  return playedPersonalityCards->size();
}
