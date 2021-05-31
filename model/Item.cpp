#include "Item.h"

Item::Item(){

}


Item::Item( string name, string description, int numTexture, bool isPotion ){
    this->name = name;
    this->description = description;
    this->isPotion = isPotion;
    if(!isPotion){
        setItem( numTexture );
    }
    else{
        setPotion( numTexture );
    }
}

Item::~Item(){

}

//NOTA: Separo las funciones por que mas adelante quiero agregar algo mas para pociones

void Item::setItem(int numTexture){
    String path;
    textureItem = new Texture();

    path = "src/images/textureItems/Item" + to_string(numTexture) + ".png" ;
    if(!textureItem->loadFromFile(path)){
        cout << "ERROR: IMG NO ENCONTRADA" << endl;
    }

}

void Item::setPotion( int numTexture){
    String path;
    textureItem = new Texture();
    
    path = "src/images/textureItems/Potions/Potion (" + to_string(numTexture) + ").png" ;
    if(!textureItem->loadFromFile(path)){
        cout << "ERROR: IMG NO ENCONTRADA" << endl;
    }

}

void Item::setSprite( Vector2f position ){
    spriteItem = new Sprite();
    spriteItem->setTexture(*textureItem);
    spriteItem->setPosition(position);
}