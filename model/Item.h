#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>
using std::string;
using namespace sf;

class Item
{
    protected:
        String name;
        String description;
        bool isPotion;

    public:

        bool getIsPotion(){ return this->isPotion; }
        String getName(){ return this->name; }

};

#endif