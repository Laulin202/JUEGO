#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

using namespace std;
using namespace sf;
using std::string;



enum button_states{ BTN_IDLE = 0, BTN_PRESSED, BTN_HOVER };


class Button
{
    private:
        RectangleShape rect; //El rectangulo (Boton)
        String id;

        Texture* textureButton;
        Sprite * sprite;
        int numBoton;

    public:
        Button();
        Button(String id, RectangleShape rect, int numBoton);
        RectangleShape getRect(){ return rect;}
        String getId(){ return id; }

        bool checkPressed( sf::Vector2i * mousePosition );
        void cargarTextura();
};

#endif