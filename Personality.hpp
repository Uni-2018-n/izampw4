#ifndef _PERSONALITY_HPP_
#define _PERSONALITY_HPP_

#include "Card.hpp"
#include "Follower.hpp"
#include "Item.hpp"

class Personality:public BlackCard{
private:
  int attack;
  int defense;
  int honor;
  bool isDead;
  Follower* possibleFollower;
  Item* PossibleItem;

public:

  Personality(string nam, personalities type);
  int getAttack();
  int getDefense();
  int getHonor();
  Follower* getpossibleFollower();
  Item* getPossibleItem();

  bool getIsDead();
  void setAttack(int x);
  void setDefense(int x);
  void setHonor(int x);
  void setIsDead(bool x);
  void setPossibleGreen(Follower* posGreen);
  void setPossibleGreen(Item* posGreen);

  void printStats();
};

#endif
