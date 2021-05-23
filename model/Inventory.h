#ifndef INVENTORY_H
#define INVENTORY_H

#include "Item.h"
#include <vector>
using std::vector;

class Inventory{

private:

    vector<Item> inventoryVector;

    int numberItems;

public:

    int getNumberItems();

    Item getItemByPosition(int itemPosition);
    
    void removeItemByPosition(int itemPosition);

    void addItem(Item itemToBeAdded);

    Inventory();

    virtual ~Inventory();

};

#endif