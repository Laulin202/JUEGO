#ifndef PAUSEMENU_H
#define PAUSEMENU_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <map>
#include "Button.h"

using namespace sf;
using std::map;

class PauseMenu{
    private:
        RectangleShape background;
        RectangleShape container;
        map<string, Button*> buttons;
        Text menuText;
        Text resumeText;
        Text quitText;
    public:
        PauseMenu( View& window, Font& font );
        void addButton( string key, int numBoton, string text, float position, float xRect, float yRect );
        int update();
        void render( RenderWindow* window);
};

#endif