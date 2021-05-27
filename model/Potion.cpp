#include "Potion.h"

Potion::Potion( string name, string description, int numTexture ){
  this->isPotion = true;
  this->name = name;
  this->description = description;
  setPotion( numTexture );
}

Potion::~Potion(){

}