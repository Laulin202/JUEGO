#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>
using std::string;
using namespace sf;
using namespace std;

class Item
{
    protected:

        Texture* textureItem;
        string name;
        string description;
        bool isPotion;

    public:
        //prueba
        Item();
        ~Item();
        Item( bool isPotion, int numTexture );
        void setItem(int numTexture);
        void setPotion(int numTexture);
        virtual bool getIsPotion(){ return isPotion; }
        string getName(){ return this->name; }
        Texture* getTexture(){ return textureItem; }
};

#endif