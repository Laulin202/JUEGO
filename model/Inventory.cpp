#include "Inventory.h"

void Inventory::addItem(Item itemToBeAdded){

    // Se verifica que el número de items no supere el máximo permitido.

    if(this->getNumberItems() < 10){

        // Se verifica que el item seleccionado sea una poción, dado el caso de que no lo sea se prosigue con otro proceso.

        if(itemToBeAdded.getIsPotion() == true){

            // Se verifica que el número de items del tipo poción no supere el máximo permitido.

            if(this->getNumberPotions() < 4){

                // Se añade la poción a la última posición de ambos vectores.

                inventoryPotionVector.push_back(itemToBeAdded);

                inventoryVector.push_back(itemToBeAdded);

                // Se agrega un elemento del contador de items de ambos vectores.

                this->numberItems+1;

                this->numberPotions+1;

            }

            else{

                // mensaje en pantalla de que el inventario  de pociones esta lleno por implementar // 5/22/21 - Steven

            }

        }

        else{

            // Se añade el item a la última posición del vector.

            inventoryVector.push_back(itemToBeAdded);

            // Se agrega un elemento al contador de items del vector.

            this->numberItems+1;

        }

    }

    else{

        // mensaje en pantalla de que el inventario esta lleno por implementar // 5/22/21 - Steven

    }

}

void Inventory::removeItemByPosition(int itemPosition){

    // Se verifica que el número de items sea mayor a cero, solamente por si acaso; no es algo realmente necesario, pero se pueden evitar errores en un futuro gracias a este condicional.

    if(this->getNumberItems() > 0){

        // Se verifica que el elemento en la posición dada se trate de una poción.

        if(getItemByPosition(itemPosition).getIsPotion() == true){

            // En caso de serlo, se procede a iterar comparando el elemento en la posición i del vector del inventario principal con todos los elementos en el sub-inventario de pociones para corroborar que se trate del mismo elemento, esto haciendo uso de String con S mayúscula porque es mejor que string con s minúscula.

            for(int i = 0; i < inventoryPotionVector.size(); i++){

                if(inventoryPotionVector[i].getName() == inventoryVector[itemPosition].getName()){

                    // Comprobando que los elementos en esa posición correspondan se procede con su eliminación.

                    inventoryVector.erase((inventoryVector.begin() + itemPosition));

                    inventoryPotionVector.erase(inventoryVector.begin() + i);

                    // Se resta 1 al contador de elementos de ambos vectores.

                    this->numberItems-1;

                    this->numberPotions-1;

                } 

            }

        }

        else{

            // En caso de que el elemento no sea una poción se procede con su eliminación de manera sencilla con la funcionalidad erase() del vector inventaryVector

            inventoryVector.erase((inventoryVector.begin() + itemPosition));

            this->numberItems-1;

        }

    }

}

int Inventory::getNumberItems(){

    // Se retorna el número de items.

    return this->numberItems;

}

Item Inventory::getItemByPosition(int itemPosition){

    // Se retorna el item dada una posición.

    return this->inventoryVector[itemPosition];

}



Inventory::Inventory(){

    // Se inicializa el número de items en 0 y los tamaños de los vectores a usarse.

    inventoryVector.resize(10);

    inventoryPotionVector.resize(4);

    numberItems = 0;

}

Inventory::~Inventory(){

}