#include "Item.h"

Item::Item(){

}


Item::Item( bool isPotion, int numTexture ){
    this->isPotion = isPotion;
    if(!isPotion){
        setItem( numTexture );
    }
    else{
        setPotion( numTexture );
    }

    this->name = "Paint";

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
    
    path = "src/images/textureItems/Pocion" + to_string(numTexture) + ".png" ;
    if(!textureItem->loadFromFile(path)){
        cout << "ERROR: IMG NO ENCONTRADA" << endl;
    }

}