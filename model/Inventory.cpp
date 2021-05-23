#include "Inventory.h"

int Inventory::getNumberItems(){

    return this->numberItems;

}

Item Inventory::getItemByPosition(int itemPosition){

    return this->inventoryVector[itemPosition];

}

void Inventory::removeItemByPosition(int itemPosition){

    if(this->getNumberItems() > 0){

        inventoryVector.erase((inventoryVector.begin() + itemPosition));

        this->numberItems-1;

    }

}

void Inventory::addItem(Item itemToBeAdded){

    if(this->getNumberItems() < 10){

        inventoryVector.push_back(itemToBeAdded);

        this->numberItems+1;

    }

    else{

        // mensaje en pantalla de que el inventario esta lleno por implementar // 5/22/21 - Steven

    }

}

Inventory::Inventory(){

    inventoryVector.resize(10);

    numberItems = 0;

}

Inventory::~Inventory(){

}