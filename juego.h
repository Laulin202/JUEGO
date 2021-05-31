#ifndef JUEGO_H
#define JUEGO_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <string>
#include <iostream>
#include "model/Entity.h"
#include "model/Player.h"
#include "model/Enemy.h"
#include "model/TileMap.h"
#include "model/InventoryMenu.h"
#include "model/Item.h"
#include "model/Potion.h"
#include "model/Weapon.h"
#include "model/Chestplate.h"
#include "model/Helmet.h"
#include "model/Leggings.h"

//Fase prueba
#include "model/Button.h"
#include "model/Combat.h"
#include "model/PauseMenu.h"
#include <list>
#include <map>
#include <ctime>

using namespace sf; //para no tener que utilizar el sf
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::list;
using std::map;


//FASE PRUEBA
enum game_states{ gameOver = 0, paused = 1, unpaused = 2, inventory = 3 };

class Juego{

    private:
        
        RenderWindow* ventana;
        PauseMenu* pMenu;
        InventoryMenu* iMenu;
        game_states gameState = unpaused;
        Font font;
        View view;
        TileMap* map;
        FloatRect mapBox;
        vector<FloatRect> tilesArray;
        multimap<int, FloatRect> puertasMap;
        Texture* tileset;
        vector<Vector2f> itemsPositions;
        vector<Item*> mapItems;
        Item* item1;
        Item* artifact;
        Player* j1;
        Enemy* e1;
        std::map<int, Enemy*> enemies;
        Clock* reloj1;
        Clock* reloj2;
        Time* cronometro1;
        int fps; //velocidad constante a la que quiero que haga el procesamiento del jugador
        int enemieInCombat;
        int contEnemiesDefeated = 0;
        Vector2f combatView;

        // Fase prueba 
        Combat* combatePlayer;
    
    public:
        /*
        Nombre: Juego
        Output: N/A
        Input: N/A
        Funcion: Recibe la resolucion para construir la ventana y llamar a la inicializacion de todo el juego.
        */
        Juego(Vector2u resolucion);

        /*
        Nombre: iniciar
        Output: N/A
        Input: N/A
        Funcion: Inicializacion de variables y diferentes aspectos importantes
        */
        void iniciar();
        
        /*
        Nombre: iniciarView
        Output: N/A
        Input: N/A
        Funcion: Genera la vista de la camara inicial y deja guardada la vista para el combate
        */
        void iniciarView();
        
        /*
        Nombre: initializeEnemiesNormal
        Output: N/A
        Input: N/A
        Funcion: Se inicializan todos los enemigos (25), en dificultad Normal, siendo guardados en un mapa con su respectiva llave.
        */
        void initializeEnemiesNormal();
        
        /*
        Nombre: initializeBasicItems
        Output: N/A
        Input: N/A
        Funcion: Inicializa todos los items que se van a mostrar por el mapa (weapons, armor y potions).
        */
        void initializeBasicItems();
        
        /*
        Nombre: initializeArtifact
        Output: N/A
        Input: N/A
        Funcion: Inicializa el artefacto final del juego.
        */
        void initializeArtifact();
        
        /*
        Nombre: pause
        Output: N/A
        Input: N/A
        Funcion: Coloca el estado del juego en pausado y crea el menu de pausa.
        */
        void pause();
        
        /*
        Nombre: openInventory
        Output: N/A
        Input: N/A
        Funcion: Coloca el estado del juego en inventario, y crea el menu del inventario.
        */
        void openInventory();
        
        /*
        Nombre: randomItemPos
        Output: Integer
        Input: N/A
        Funcion: Genera un entero aleatorio para colocar una posicion aleatoria del array de posiciones a cada item.
        */
        int randomItemPos();
        
        /*
        Nombre: updateState
        Output: enum game_states
        Input: Integer
        Funcion: Retorna un estado del juego dependiendo del entero que reciba
        */
        game_states updateState( int state );
        
        /*
        Nombre: loadMap
        Output: N/A
        Input: N/A
        Funcion: Se crea y se carga el mapa, guardando de una vez las puertas bloqueadas y un arreglo de los espacios.
        */
        void loadMap();
        
        /*
        Nombre: renderizar
        Output: N/A
        Input: N/A
        Funcion: Se encarga de dibujar en la ventana todo lo que se debe mostrar una vez ya procesada la logica, claramente evaluando que algunas de las cosas que se van a dibujar existan.
        */
        void renderizar(); 
        
        /*
        Nombre: procesarLogica
        Output: N/A
        Input: N/A
        Funcion: Se encarga de evaluar las colisiones y los movimientos en el juego.
        */
        void procesarLogica(); 
        
        /*
        Nombre: procesarNetworking
        Output: N/A
        Input: N/A
        Funcion: Evalua que teclas clave se estan presionando (ESC).
        */
        void procesarNetworking(); 
        
        /*
        Nombre: updateBorderCollision
        Output: N/A
        Input: N/A
        Funcion: Evalua si el jugador esta colisionando con alguna parte del borde del mapa.
        */
        void updateBorderCollision();
        
        /*
        Nombre: updateItemsCollision
        Output: N/A
        Input: N/A
        Funcion: Evalua si el jugador esta colisionando con algun item que se encuentre en el mapa
        */
        void updateItemsCollision();
        
        /*
        Nombre: updateTileCollision
        Output: N/A
        Input: N/A
        Funcion: Evalua si el jugador esta colisionando con algun bloque del mapa que no se puede pasar.
        */
        bool updateTileCollision();
        
        /*
        Nombre: updateView
        Output: N/A
        Input: N/A
        Funcion: Actualiza la vista de la camara para que siempre vaya con el jugador.
        */
        void updateView();
        
        /*
        Nombre: gameLoop
        Output: N/A
        Input: N/A
        Funcion: Se genera el ciclo dentro del cual va a procesarse todo el juego.
        */
        void gameLoop();


};

#endif