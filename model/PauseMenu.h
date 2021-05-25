#ifndef PAUSEMENU_H
#define PAUSEMENU_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <map>
#include "PauseMenu.h"
#include "Button.h"

class PauseMenu{
    private:
        RectangleShape background;
        RectangleShape container;
        map<string, Button*> buttons;
    public:
        PauseMenu();
        PauseMenu( RenderWindow& window );
        void update();
        void render( RenderTarget& window);
};

#endif