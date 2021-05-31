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
        Sprite* spriteItem;
        FloatRect itemHitBox;
        string name;
        string description;
        bool isPotion = false;

    public:
        //prueba
        Item();
        ~Item();
        Item( string name, string description, int numTexture, bool isPotion, Vector2f position );
        void setSprite(Vector2f position); // Se crea el sprite
        void setHitBox(Vector2f position); // Se crea la hitbox
        void setItem(int numTexture); // Se coloca la textura si no es pocion
        void setPotion(int numTexture); // Se coloca la textura si es pocion
        virtual bool getIsPotion(){ return isPotion; } // Retorna si es pocion o no
        string getName(){ return this->name; } // Retorna el nombre
        Texture* getTexture(){ return textureItem; } // Retorna la textura
        Sprite* getSprite(){ return spriteItem; } // Retorna el sprite
        FloatRect getHitBox(){ return itemHitBox; } // Retorna la hitbox
};

#endif