#ifndef JUEGO_H
#define JUEGO_H

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
        
        RenderWindow* ventana;
        bool gameOver = false;
        Player* j1;
        Clock* reloj1;
        Time* cronometro1;
        int fps; //velocidad constante a la que quiero que haga el procesamiento del jugador
        
    
    
    
    
    public:
        Juego(Vector2u resolucion);
        void iniciar(); //Inicializacion de variables y diferentes aspectos importantes
        void renderizar(); //Dibujando en pantalla los elementos del juego
        void procesarLogica(); // Procesa Logica del juego
        void procesarEventos(); // Procesa logica del juego
        void procesarNetworking(); //Procesa, teclado, mouse etc
        void gameLoop();
};

#endif