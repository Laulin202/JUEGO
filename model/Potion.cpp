#include "Potion.h"

Potion::Potion( string name, string description, int numTexture, int effectValue, int effectType, int duration, Vector2f position ){
  Item( name, description, numTexture, true, position );
  this->effectValue = effectValue;
  this->effectType = effectType;
  this->duration = duration;

  setPotion( numTexture );
}

Potion::~Potion(){

}