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

bool Player::fillTopOfProvince(BlackCard* card){//fills an empty space for topOfProvinces used card
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

int Player::getTopOfProvinceCount(){//returns the size of full topOfProvince cards(holdings and personalities)
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

void Player::printTopOfProvince(){//prints all the topOfProvinces(both holdings and Personalities)
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

void Player::printHoldings(){
  if(playedHoldingCards->size() == 0){
    cout << "No Holding Cards in the Arena" << endl;
    return;
  }
  list<Holding*>::iterator it;
  for(it= playedHoldingCards->begin(); it != playedHoldingCards->end(); it++){
    (*it)->printStats();
  }
  cout << endl;
}

void Player::printPersonalities(){
  if(playedPersonalityCards->size() == 0){
    cout << "No Personality Cards in the Arena" << endl;
    return;
  }
  list<Personality*>::iterator it;
  for(it= playedPersonalityCards->begin(); it != playedPersonalityCards->end(); it++){
    (*it)->printStats();
  }
  cout << endl;
}

//////////////////////////////////////////////Starter Phase
void Player::printCurrState(){//prints every statistic about player
  cout << "//////////Stronghold: ";
  a.print();

  cout << "Curr Cash: " << money << endl;

  cout << "//////////Top of provinces:" << endl;
  printTopOfProvince();
  cout << "//////////Provinces: " << numOfProv << endl;
  printProvinces();

  cout << "//////////Curr Hand: " << endl;
  currHand->print();
  cout<< "///////////Holdings: "<<endl;
  printHoldings();
  cout<< "///////////Personalities: "<<endl;
  printPersonalities();
}

void Player::untapEverything(){//untaps every player's card
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

//TODO reveal topOfProvinces too if needed(agorase neo topOfProvince kai sto starter phase prepei na ginetai unrevealed, eimai arketa sigouros oti ginetai mono untaped)
void Player::revealProvinces(){//reveals player's provinces
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

void Player::drawFateCard(){//draw a single green card and add it to hand
    if(currHand->addToHand(fateDeck->front())){
      fateDeck->pop_front();
    }
}

//////////////////////////////////////////////Equip Phase
void Player::printHand(){
  currHand->print();
}

void Player::printArmy(){//print only personality cards played in the Arena
  int count=0;
  list<Personality*>::iterator it;
  for(it = playedPersonalityCards->begin(); it != playedPersonalityCards->end(); it++){
    cout << "<" << count++ << ">:";
    (*it)->printStats();
    cout << endl;
  }
  cout << endl;
}

void Player::printOptions(){//print options(used for curr player to view not for enemies)
  cout<<"Printing Hand : "<<endl;
  printHand();
  cout<<"Printing Army : "<< endl;
  printArmy();
}

int Player::getCountOfPlayedPersonalityCards(){
  return playedPersonalityCards->size();
}

void Player::equipCardToArmy(int cardIndex, int armyIndex){//equip green card to personality card, does the money and everything
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
  if(money >= currCard->getCost()){//if its financialy capable to buy the card
    if((currArmy->getPossibleItem() == NULL) && (currArmy->getpossibleFollower() == NULL)){//check if personality already has a green card
      if(currArmy->getHonor() >= currCard->getMinimumHonour()){//get if personality is high-honour enough
        money = money -currCard->getCost();//update money
        currArmy->setAttack(currArmy->getAttack() + currCard->getAttackBonus());//and update card statistics
        currArmy->setDefense(currArmy->getDefense() + currCard->getDefenseBonus());
        if((currCard->getCategory()) == "item"){
          currArmy->setPossibleGreen((Item*)currCard);
        }else{
          currArmy->setPossibleGreen((Item*)currCard);
        }
        if(money >= currCard->getEffectCost()){//check if its possible to upgrade the effect of the card and ask player
          cout<<"Do you want to upgrade the card for the cost of "<<currCard->getEffectCost() <<" coins?[0=no/1=yes]: ";
          cin >>response;
          if(response==1){
            money=money-currCard->getEffectCost();
            currArmy->setAttack(currArmy->getAttack() + currCard->getEffectBonus());
            currArmy->setDefense(currArmy->getDefense() + currCard->getEffectBonus());
          }
        }
        cout << "-----SUCCESS" << endl;
        removeHandCard(cardIndex);//remove it from playable hands in card
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
    if((*it)->getIsRevealed() == true){//TODO 2.4 1h par teleytaia protash
      cout << count << ": ";
      (*it)->print();
    }else{
      cout << count << ": (PROVINCE UNREVEALED)  |  ";
    }
    count++;
  }
  cout << endl;
}

void Player::printOptionsByEnemys(){//print what enemies can see
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

void Player::destroyProvince(int prov){//remove province with index prov
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

void Player::destroyCards(Provinces* prov){//destroy cards used to defend the province
  list<Personality*>::iterator it;
  for(it=playedPersonalityCards->begin(); it != playedPersonalityCards->end(); it++){
    list<Personality*>::iterator it2;
    for(it2=prov->getDefendingCards()->begin(); it2 != prov->getDefendingCards()->end(); it2++){
      if((*it) == (*it2)){//TODO paizei na bgalei problhma ayth h grammh :(
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
    if((*it)->getSubCategory()=="MINE"&&(*it)->getHasUpperHolding()==0){

      return count;  int findGoldMineWithoutUpper();

    }
    count++;
  }
  return -1;
}

int Player::findGoldMineWithoutSub(){

  list<Holding*>::iterator it;
  int count=0;
  for(it= playedHoldingCards->begin(); it !=playedHoldingCards->end(); it++){
    if((*it)->getSubCategory()=="GOLD_MINE"&&(*it)->getHasSubHolding()==0){
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
    if((*it)->getSubCategory()=="GOLD_MINE"&&(*it)->getHasUpperHolding()==0){
      return count;
    }
    count++;
  }
  return -1;
}

int Player::findCrystalMine(){

  list<Holding*>::iterator it;
  int count=0;
  for(it= playedHoldingCards->begin(); it !=playedHoldingCards->end(); it++){  int findGoldMineWithoutUpper();

    if((*it)->getSubCategory()=="CRYSTAL_MINE"&&(*it)->getHasSubHolding()==0){
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
