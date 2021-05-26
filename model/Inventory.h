#ifndef INVENTORY_H
#define INVENTORY_H

#include "Item.h"
#include <vector>
#include <string.h>
#include <iostream>

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;


class Inventory{

private:

    //Vector del inventario general (item y pociones).

    vector<Item> inventoryVector;

    //Vector del sub-inventario de pociones.

    vector<Item> inventoryPotionVector;

    // Número de items del inventario general.

    int numberItems;

    //Número de pociones en el sub-inventario.

    int numberPotions;

public:

    Inventory();

    virtual ~Inventory();
    

    /* Añade items al inventario general y al inventario de pociones, esto antes revisando el item dado corresponda a una poción. Revisar los comentarios dentro de la función para más detalles.*/

    void addItem(Item itemToBeAdded);

    /* Elimina items al inventario general y al inventario de pociones dada una posición, esto antes revisando el item dado corresponda a una poción. Revisar los comentarios dentro de la función para más detalles.*/

    
    void removeItemByPosition(int itemPosition);

    /* Retorna un entero que corresponde al número de items en el inventario general (incluyendo las pociones)*/    

    int getNumberItems();

    /* Retorna un entero que corresponde al número de pociones en el sub-inventario de estas mismas*/ 

    int getNumberPotions(){return this->numberPotions;};

    /* Retorna un item, incluyendo pociones dada una posición dentro del inventario. Revisar los comentarios dentro de la función para más detalles*/ 

    Item getItemByPosition(int itemPosition);

    /* Constructor y destructor*/ 



};

#endif