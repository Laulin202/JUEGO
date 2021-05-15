#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "model/Entity.h"
#include "model/Player.h"

using namespace sf; //para no tener que utilizar el sf
using std::string;
using std::cout;
using std::cin;

class Juego{

    private:
        RenderWindow* ventanaJuego;
        Player* player1;
    public:
        //Constructor del juego.
        Juego(int resolucion_x, int resolucion_y, string titulo);
        //Dibuja(muestra) la pantalla
        void dibujarPantalla();
        //Lopp para mostrar permanentemente la ventana
        void gameLoop();
        //inicializar textura
        //nose
        //bool spriteTime(Time elapsed1);

        


};