#include "Weapon.h"

Weapon::Weapon(string name, string description, int numWeapon, int bonusAttack, Vector2f position){
    this->name = name;
    this->description = description;
    this->bonusAttackPoints = bonusAttack;
    setTexture(numWeapon);
    setSprite(position);
}

void Weapon::setTexture( int numWeapon ){
    String path;
    textureItem = new Texture();

    path = "src/images/textureItems/Weapons/Weapon (" + to_string(numWeapon) + ").png" ;
    if(!textureItem->loadFromFile(path)){
        cout << "ERROR: IMG NO ENCONTRADA" << endl;
    }

}