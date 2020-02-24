#include "Player.hpp"
Player::Player(DeckBuilder& deck){
  //setters
  money=a.getMoney();
  honour = a.getHonour();
  fateDeck = deck.createFateDeck();
  deck.deckShuffler(fateDeck);
  dynastyDeck = deck.createDynastyDeck();
  deck.deckShuffler(dynastyDeck);
  playedPersonalityCards = new list<Personality*>();

  //uncomment this if you want to add testing personalities
  // while(dynastyDeck->front()->getCategory() != "personality"){
  //   dynastyDeck->pop_front();
  // }
  // Personality* temp= (Personality*)((dynastyDeck->front()));
  // temp->setIsRevealed(true);
  // playedPersonalityCards->push_back(temp);
  // dynastyDeck->pop_front();
  // while(dynastyDeck->front()->getCategory() != "personality"){
  //   dynastyDeck->pop_front();list <Holding*>::iterator it;//GOLD_MINE

            
  // }
  // temp= (Personality*)((dynastyDeck->front()));
  // temp->setIsRevealed(true);
  // playedPersonalityCards->push_back(temp);
  // dynastyDeck->pop_front();
  // while(dynastyDeck->front()->getCategory() != "personality"){
  //   dynastyDeck->pop_front();
  // }
  // temp= (Personality*)((dynastyDeck->front()));
  // temp->setIsRevealed(true);
  // playedPersonalityCards->push_back(temp);
  // dynastyDeck->pop_front();
  // while(dynastyDeck->front()->getCategory() != "personality"){
  //   dynastyDeck->pop_front();
  // }
  // temp= (Personality*)((dynastyDeck->front()));
  // temp->setIsRevealed(true);
  // playedPersonalityCards->push_back(temp);
  // dynastyDeck->pop_front();

  playedHoldingCards = new list<Holding*>();

  playedFollowerCards = new list<Follower*>();
  playedItemCards = new list<Item*>();


  //create provinces, push_back a new province with a black card and stronghold as arguments
  provinces = new list<Provinces *>();
  for(int i=0;i<4;i++){
    provinces->push_back(new Provinces(*(dynastyDeck->front()), a));
    dynastyDeck->pop_front();
  }
  numOfProv=4;

  //then create the top-of-provinces-cards(einai unrevealed, arxh ka8e gyroy ginontai revealed oses einai katw)
  //aytes tis kartes mporei o pekths na tis agorasei an 8elei(TODO)
  topOfProvincePersonality = new list<Personality*>();
  topOfProvinceHolding = new list<Holding*>();

  for(int i=0;i<4;i++){
    if(fillTopOfProvince(dynastyDeck->front())){
      dynastyDeck->pop_front();
    }else{
      break;
    }
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

bool Player::fillTopOfProvince(BlackCard* card){
  if(getTopOfProvinceCount() < getCountOfProvinces()){
    if(card->getCategory() == "holding"){
      topOfProvinceHolding->push_back((Holding*)card);
    }else if(card->getCategory() == "personality"){
      topOfProvincePersonality->push_back((Personality*)card);
    }
    return true;
  }else{
    return false;
  }
}

int Player::getTopOfProvinceCount(){
  int count=0;
  {
    list<Personality*>::iterator it;
    for(it=topOfProvincePersonality->begin(); it != topOfProvincePersonality->end(); it++){
      count++;
    }
  }

  {
    list<Holding*>::iterator it;
    for(it=topOfProvinceHolding->begin(); it != topOfProvinceHolding->end(); it++){
      count++;
    }
  }
  return count;
}

void Player::printTopOfProvince(){
  int count=0;
  {
    list<Personality*>::iterator it;
    for(it=topOfProvincePersonality->begin(); it != topOfProvincePersonality->end(); it++){
      cout << count << ": ";
      (*it)->printStats(true);
      count++;
    }
  }

  {
    list<Holding*>::iterator it;
    for(it= topOfProvinceHolding->begin(); it != topOfProvinceHolding->end(); it++){
      cout << count << ": ";
      (*it)->printStats(true);
      count++;
    }
  }
  cout << endl;
}

//////////////////////////////////////////////Starter Phase
void Player::printCurrState(){
  cout << "//////////Stronghold: ";
  a.print();
  cout << endl;
  cout << "//////////Top of provinces:" << endl;
  printTopOfProvince();
  cout << "//////////Provinces: " << numOfProv << endl;
  {
    list<Provinces *>::iterator it;//print ta provinces
    for(it = provinces->begin(); it != provinces->end(); it++)
      if((*it)->getIsRevealed() == true)//2.4 1h par teleytaia protash
        (*it)->print();
      else
        cout << "(PROVINCE UNREVEALED)  |  ";
  }
  cout << endl << endl;

  cout << "//////////Curr Hand: " << endl;
  currHand->print();

  cout << endl << endl;
}

void Player::untapEverything(){
  {
  list<Personality *>::iterator it;
  for(it = playedPersonalityCards->begin(); it != playedPersonalityCards->end(); it++)
    (*it)->setIsTapped(false);
  }
  {
  list<Follower *>::iterator it;
  for(it = playedFollowerCards->begin(); it != playedFollowerCards->end(); it++)
    (*it)->setIsTapped(false);
  }

  {
  list<Holding *>::iterator it;
  for(it = playedHoldingCards->begin(); it != playedHoldingCards->end(); it++)
    (*it)->setIsTapped(false);
  }
  {
  list<Item *>::iterator it;
  for(it = playedItemCards->begin(); it != playedItemCards->end(); it++)
    (*it)->setIsTapped(false);
  }
}

void Player::revealProvinces(){
  {
    list<Personality*>::iterator it;
    for(it = topOfProvincePersonality->begin(); it != topOfProvincePersonality->end(); it++)
    (*it)->setIsRevealed(true);
  }
  {
    list<Holding*>::iterator it;
    for(it = topOfProvinceHolding->begin(); it != topOfProvinceHolding->end(); it++)
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

//////////////////////////////////////////////Equip Phase
void Player::printHand(){
  currHand->print();
}

void Player::printArmy(){
  int count=0;
  list<Personality*>::iterator it;
  for(it = playedPersonalityCards->begin(); it != playedPersonalityCards->end(); it++){
    cout << "<" << count++ << ">:";
    (*it)->printStats();
    cout << endl;
  }
  cout << endl;
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

void Player::equipCardToArmy(int cardIndex, int armyIndex){
  int armyCount=0;
  int response;
  GreenCard* currCard= currHand->getCardFromIndex(cardIndex);
  Personality* currArmy;
  {
    list<Personality*>::iterator it;
    for(it= playedPersonalityCards->begin(); it != playedPersonalityCards->end(); it++){
        if(armyCount == armyIndex){
          currArmy = (*it);
        }
        armyCount++;
    }
  }

  if(money >= currCard->getCost()){
    if((currArmy->getPossibleItem() == NULL) && (currArmy->getpossibleFollower() == NULL)){
      if(currArmy->getHonor() >= currCard->getMinimumHonour()){
        money = money -currCard->getCost();
        currArmy->setAttack(currArmy->getAttack() + currCard->getAttackBonus());
        currArmy->setDefense(currArmy->getDefense() + currCard->getDefenseBonus());
        if((currCard->getCategory()) == "item"){
          currArmy->setPossibleGreen((Item*)currCard);
        }else{
          currArmy->setPossibleGreen((Item*)currCard);
        }
        if(money >= currCard->getEffectCost()){
          cout<<"Do you want to upgrade the card for the cost of "<<currCard->getEffectCost() <<" coins?[0=no/1=yes]"<<endl;
          cin >>response;
          if(response==1){
            money=money-currCard->getEffectCost();
            currArmy->setAttack(currArmy->getAttack() + currCard->getEffectBonus());
            currArmy->setDefense(currArmy->getDefense() + currCard->getEffectBonus());
          }
        }
        cout << "-----SUCCESS" << endl;
        removeHandCard(cardIndex);
      }else{
        cout << "Cant play card cause honor of army is not enough" << endl;
      }
    }else{
      cout << "Already played a GreenCard for this Personality" << endl;
    }
  }else{
    cout << "cant afford the cost of this card" << endl;
  }
  cout << endl;
}

int Player::getCurrHandPl(){
  return currHand->currPl();
}

void Player::removeHandCard(int cardIndex){
  currHand->removeCard(cardIndex);
}


//////////////////////////////////////////////Battle Phase
list<Personality*>* Player::getPlayedPersonalityCards(){
  return playedPersonalityCards;
}

void Player::printProvinces(){
  int count=0;
  list<Provinces *>::iterator it;//print ta provinces
  for(it = provinces->begin(); it != provinces->end(); it++){
    if((*it)->getIsRevealed() == true){//2.4 1h par teleytaia protash
      cout << count << ": ";
      (*it)->print();
    }else{
      cout << count << ": (PROVINCE UNREVEALED)  |  ";
    }
    count++;
  }
  cout << endl;
}

void Player::printOptionsByEnemys(){
  cout<<"Printing Provinces : "<<endl;
  printProvinces();
  cout << endl;
}

int Player::getCountOfProvinces(){
  return provinces->size();
}

list<Provinces*>* Player::getProvinces(){
  return provinces;
}

void Player::destroyProvince(int prov){//had to change it advance didnt work...
  list<Provinces *>::iterator it;
  int count=0;
  for(it=provinces->begin(); it != provinces->end(); it++){
    if(count == prov){
      break;
    }
    count++;
  }
  provinces->erase(it);
}

void Player::destroyCards(Provinces* prov){
  list<Personality*>::iterator it;
  for(it=playedPersonalityCards->begin(); it != playedPersonalityCards->end(); it++){
    list<Personality*>::iterator it2;
    for(it2=prov->getDefendingCards()->begin(); it2 != prov->getDefendingCards()->end(); it2++){
      if((*it) == (*it2)){//paizei na bgalei problhma ayth h grammh :(
        playedPersonalityCards->erase(it);
        prov->getDefendingCards()->erase(it2);
      }
    }
  }
}




//////////////////////////////////////////////Chains
int Player::findMine(){

  list<Holding*>::iterator it;
  int count=0;
  for(it= playedHoldingCards->begin(); it !=playedHoldingCards->end(); it++){
    if((*it)->getSubcategory()=="MINE"&&(*it)->getHasUpperHolding()==0){

      return count;
    }
    count++;
  }
  return -1;
}

int Player::findGoldMineWithoutSub(){

  list<Holding*>::iterator it;
  int count=0;
  for(it= playedHoldingCards->begin(); it !=playedHoldingCards->end(); it++){
    if((*it)->getSubcategory()=="GOLD_MINE"&&(*it)->getHasSubHolding()==0){
      return count;
    }
    count++;
  }
  return -1;
}

int Player::findGoldMineWithoutUpper(){

  list<Holding*>::iterator it;
  int count=0;
  for(it= playedHoldingCards->begin(); it !=playedHoldingCards->end(); it++){
    if((*it)->getSubcategory()=="GOLD_MINE"&&(*it)->getHasUpperHolding()==0){
      return count;
    }
    count++;
  }
  return -1;
}

int Player::findCrystalMine(){

  list<Holding*>::iterator it;
  int count=0;
  for(it= playedHoldingCards->begin(); it !=playedHoldingCards->end(); it++){
    if((*it)->getSubcategory()=="CRYSTAL_MINE"&&(*it)->getHasSubHolding()==0){
      return count;
    }
    count++;
  }
  return -1;
}

void Player::printBuyingOptionsBlack(){
  cout << "Printing available Black Cards for purchase:" << endl;
  printTopOfProvince();
}

void Player::printBuyingOptionsGreen(){
  cout <<"Printing available Green Cards for purchase: " <<endl;
  {
    printHand();
  }
}


list<Holding*>* Player::getTopOfProvinceHolding(){
  return topOfProvinceHolding;
}

list<Personality*>* Player::getTopOfProvincePersonality(){
  return topOfProvincePersonality;
}

void Player::increaseMoney(int a){
  money +=a;
}
