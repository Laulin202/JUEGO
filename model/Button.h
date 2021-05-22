#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <string>


using std::string;
using namespace sf;

enum button_states{ BTN_IDLE = 0, BTN_PRESSED, BTN_HOVER };


class Button
{
    private:
        RectangleShape rect; //El rectangulo (Boton)
        String id;

        sf::Texture * texture;
        sf::Sprite * sprite;
    public:
        Button();
        Button(String id, RectangleShape rect){ this->id = id; this->rect = rect;}
        RectangleShape getRect(){ return rect;}
        String getId(){ return id; }

        bool checkPressed( sf::Vector2i * mousePosition );
};

#endif