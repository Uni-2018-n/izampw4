#include "Card.hpp"

class Personalities:public BlackCard{
protected:
  bool IsRevealed;
  int attack;
  int defense;
  int honor;

public:
  Personalities(string nam, personalities type);
};
