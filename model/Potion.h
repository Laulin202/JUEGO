#ifndef POTION_H
#define POTION_H
#include "Item.h"

enum effectType{ increaseAttackPointsE, restoreHealthPointsE, restoreManaE };

class Potion : public Item
{
  private:
    int effectValue;
    int effectType;
    int duration;
  //Constructors / Destructors
  public:
    Potion( string name, string description, int numTexture, int effectValue, int effectType, int duration );
    ~Potion();
    bool getIsPotion(){ return true; } 
    int getEffectValue(){ return this->effectValue; }
    int getEffectType(){ return this->effectType; }
    int getDuration(){ return this->duration; }
};


#endif