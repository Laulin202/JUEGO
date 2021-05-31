#include "Chestplate.h"

Chestplate::Chestplate(string name, string description, int numArmor, int bonusResistance, Vector2f position){
    this->name = name;
    this->description = description;
    this->bonusResistancePoints = bonusResistance;
    setTexture(numArmor);
    setSprite(position);
}

void Chestplate::setTexture( int numArmor ){
    String path;
    textureItem = new Texture();

    path = "src/images/textureItems/Accesorios/Pechera (" + to_string(numArmor) + ").png" ;
    if(!textureItem->loadFromFile(path)){
        cout << "ERROR: IMG NO ENCONTRADA" << endl;
    }
}