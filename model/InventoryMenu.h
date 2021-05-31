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
        /*
        Nombre: addButton
        Output: N/A
        Input: string, int, string, float, float, float
        Funcion: Se crea y se agrega el boton al menu de pausa
        */
        void addButton( string key, int numBoton, string text, float position, float xRect, float yRect );

        /*
        Nombre: update
        Output: int
        Input: N/A
        Funcion: Retorna la opcion seleccionada en el menu de pausa
        */
        int update();

        /*
        Nombre: render
        Output: N/A
        Input: N/A
        Funcion: Dibuja el background, el container y los botones.
        */
        void render( RenderWindow* window);
};

#endif