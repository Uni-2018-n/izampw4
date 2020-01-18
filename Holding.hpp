#include "Card.hpp"

class Holding:public BlackCard{
protected:
  int harvest;

public:
  Holding(string nam, holdings type);
};
