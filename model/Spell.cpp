#include "Spell.h"

Spell::Spell(){
    
}

Spell::Spell( String name, String description, int damage, int manaCost){
    this->name = name;
    this->description = description;
    this->damage = damage;
    this->manaCost = manaCost;
}