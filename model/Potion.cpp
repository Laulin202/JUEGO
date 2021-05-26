#include "Potion.h"

Entity::Entity( string name, string description, int numTexture ){
  Item( true, numTexture );
  this->name = name;
  this->description = description;
}
Entity::~Entity(){

}