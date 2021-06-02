#include "Leggings.h"

Leggings::Leggings(string name, string description, int numLeggings, int bonusResistance, Vector2f position){
    this->name = name;
    this->description = description;
    this->bonusResistancePoints = bonusResistance;
    setTexture(numLeggings);
    setSprite(position);
}

void Leggings::setTexture( int numLeggings ){
    String path;
    textureItem = new Texture();

    path = "src/images/textureItems/Accesorios/Perneras (" + to_string(numLeggings) + ").png" ;
    if(!textureItem->loadFromFile(path)){
        cout << "ERROR: IMG NO ENCONTRADA" << endl;
    }
}