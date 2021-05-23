#ifndef PAUSEMENU_H
#define PAUSEMENU_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include "PauseMenu.h"
#include "Button.h"

class PauseMenu{
    private:
        RectangleShape background;
        vector<Button> pauseButtons;
    public:
        PauseMenu(RenderWindow& window);
        void update();
        void render( RenderTarget& target);
};

#endif