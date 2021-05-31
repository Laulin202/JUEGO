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

//Fase prueba
#include "model/Button.h"
#include "model/Combat.h"
#include "model/PauseMenu.h"
#include <list>
#include <map>

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
        Item* item1;
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
        Juego(Vector2u resolucion);
        void iniciar(); //Inicializacion de variables y diferentes aspectos importantes
        void iniciarView();
        void initializeEnemiesNormal();
        void initializeBasicItems();
        void pause();
        void unpause();
        void openInventory();
        game_states updateState( int state );
        void loadMap();
        void renderizar(); //Dibujando en pantalla los elementos del juego
        void renderizarPauseMenu();
        void procesarLogica(); // Procesa Logica del juego
        void procesarEventos(); // Procesa eventos del juego
        void procesarNetworking(); //Procesa, teclado, mouse etc
        void updateBorderCollision();
        bool updateTileCollision();
        void updateView();
        void gameLoop();
        
        //fASE PRUEBA
        
        void procesarLogicaCombate(); //TODO: Actualizar.


};

#endif