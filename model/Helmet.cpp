#include "Helmet.h"

Helmet::Helmet(string name, string description, int numHelmet, int bonusResistance, Vector2f position){
    this->name = name;
    this->description = description;
    this->bonusResistancePoints = bonusResistance;
    setTexture(numHelmet);
    setSprite(position);
}

void Helmet::setTexture( int numHelmet ){
    String path;
    textureItem = new Texture();

    path = "src/images/textureItems/Accesorios/Helmet (" + to_string(numHelmet) + ").png" ;
    if(!textureItem->loadFromFile(path)){
        cout << "ERROR: IMG NO ENCONTRADA" << endl;
    }
}