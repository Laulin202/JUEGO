#ifndef POTION_H
#define POTION_H
#include "Item.h"

enum effectType{ increaseAttackPoints, increaseMagicAttackPoints, restoreHealthPoints, restoreMana };

class Potion : public Item
{
public:
  private:
  int effectValue;
  int effectType;
  //Constructors / Destructors
  public:
  Potion( string name, string description, int numTexture );
  ~Potion();
  int getEffectValue(){ return this->effectValue; }
  int getEffectType(){ return this->effectType; }
};


#endif