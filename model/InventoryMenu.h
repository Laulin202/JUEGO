#ifndef INVENTORYMENU_H
#define INVENTORYMENU_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <map>
#include "Button.h"

using namespace sf;
using std::map;

class InventoryMenu{
    private:
        RectangleShape background;
        RectangleShape containerItems;
        Texture* containerItemsTex;
        Texture* containerArmorTex;
        RectangleShape containerArmor;
        map<string, Button*> buttons; 
        Text menuText;
    public:
        InventoryMenu( View& window, Font& font );
        void addButton( string key, int numBoton, string text, float position, float xRect, float yRect );
        int update();
        void render( RenderWindow* window);
};

#endif