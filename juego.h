#ifndef JUEGO_H
#define JUEGO_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "model/Entity.h"
#include "model/Player.h"
#include "model/Enemy.h"
#include "model/TileMap.h"

//Fase prueba
#include "model/Button.h"
#include "model/Combat.h"
#include <list>

using namespace sf; //para no tener que utilizar el sf
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::list;


//FASE PRUEBA


class Juego{

    private:
        
        RenderWindow* ventana;
        bool gameOver = false;
        bool paused = false;
        View view;
        TileMap* map;
        FloatRect mapBox;
        vector<FloatRect> tilesArray;
        Texture* tileset;
        Player* j1;
        Enemy* e1;
        Clock* reloj1;
        Time* cronometro1;
        int fps; //velocidad constante a la que quiero que haga el procesamiento del jugador

        // Fase prueba 
        Combat* combatePlayer;
    
    public:
        Juego(Vector2u resolucion);
        void iniciar(); //Inicializacion de variables y diferentes aspectos importantes
        void iniciarView();
        void pause();
        void unpause();
        void loadMap();
        void renderizar(); //Dibujando en pantalla los elementos del juego
        void procesarLogica(); // Procesa Logica del juego
        void procesarEventos(); // Procesa logica del juego
        void procesarNetworking(); //Procesa, teclado, mouse etc
        void updateCollision();
        bool updateTileCollision();
        void updateView();
        void gameLoop();
        
        //fASE PRUEBA
        
        void procesarLogicaCombate(); //TODO: Actualizar.


};

#endif