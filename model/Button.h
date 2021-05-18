#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>

enum button_states{ BTN_IDLE = 0, BTN_PRESSED, BTN_HOVER };


class Button
{
    private:
        short unsigned buttonState;
        bool pressed;
        bool hover;
        sf::Texture * texture;
        sf::Sprite * sprite;
    public:
        bool checkPressed( sf::Vector2i * mousePosition );
};

#endif