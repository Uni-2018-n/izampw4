#include <iostream>
using namespace std;



class Card{
protected:
  string name;
  int cost;
  bool isTapped;
public:
  Card(string nam, int cos, bool iTap);
};

/////////////////////////////////////////////<GreenCard>
class GreenCard:public Card{//this should be abstruct
protected:
  int attackBonus;
  int defenceBonus;
  int minimumHonour;
  int effectBonus;
  int effectCost;

  string cardText;
public:
  GreenCard(string nam, int cos, int attacB, int defencB, int minH, int effecB, int effecC, string cardT);

};

class Follower:public GreenCard{//prosopikh froyra, this should be abstruct
public:
  Follower(string nam, int cos, int attacB, int defencB, int minH, int effecB, int effecC, string cardT);
};

//akolou8oi
class FootSoldier:public Follower{
private:

public:
  FootSoldier(string nam, string cardT):
};

class Archer:public Follower{
private:

public:
  Archer(string nam, string cardT);
};

class Cavalry:public Follower{
private:

public:
  Cavalry(string nam, string cardT);
};

class Bushido:public Follower{
private:

public:
  Bushido(string nam, string cardT):
};

class Sieger:public Follower{
private:

public:
  Sieger(string nam, string cardT):
};

class Naval:public Follower{
private:

public:
  Naval(string nam, string cardT):
};
//</akolou8oi>


class Item:public GreenCard{//eksoplismos prosopikothtas
private:
  int durability;
public:
  Item(string nam, int cos, int attacB, int defencB, int minH, int effecB, int effecC, string cardT, int dur);
};

//antikeimena
class Katana:public Item{

};

class Spear:public Item{

};

class Bow:public Item{

};

class Ninjato:public Item{

};

class Wakizashi:public Item{

};
//</antikeimena>

/////////////////////////////////////////////</GreenCard>

/////////////////////////////////////////////<BlackCard>
class BlackCard:public Card{
protected:
  bool IsRevealed;
  int cost;
public:
  BlackCard(string nam, int cos);
};

class Personalities:public BlackCard{
private:

public:
  Personalities();
  int attack;
  int defense;
  int honor;
  bool isDead;

};

class Holding:public BlackCard{


public:
  Holding(string nam, int cos);
  int harvest;

};

class Stronghold:public BlackCard{
private:
  int honor;
  int money;
  int InitialDefense;
public:
  Stronghold(string nam, int cos);
};
/////////////////////////////////<Personalities>
class Attacker:public Personalities{
public:
  Attacker();
};

class Defender:public Personalities{
public:
  Defender();

};

class Shogun:public Personalities{
public:
  Shogun();
};

class Chancellor:public Personalities{
public:
  Chancellor();
};

class Champion:public Personalities{
public:
  Champion();
};

/////////////////////////////////<Holding>
class Solo:public Holding{
public:
  Solo();
};

class Plain:public Holding{
public:
  Plain();

};


class Farms:public Holding{
public:
  Farms();
};


class Mine:public Holding{
public:
  Mine();

};


class GoldMine:public Holding{
public:
  GoldMine();
};


class CrystalMine:public Holding{
public:
  CrystalMine();
};























//////////////////////////////////////////////</BlackCard>
