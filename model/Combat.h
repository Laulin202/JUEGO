#ifndef COMBAT_H
#define COMBAT_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include "Boss.h"
#include "Spell.h"
#include <time.h>
#include <stdlib.h>

//Fase prueba
#include <iostream>
#include "Button.h"
#include <list>

using namespace sf; //para no tener que utilizar el sf
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::list;

enum estadosB{ atacar, escapar, inventario, menu };

enum{
    PLAYERWON = true, ENEMYWON = false
};

class Combat
{
    private:
        Player* player;
        Enemy * enemy;
        int turn;

        //FASE PRUEBA

        list<Button> listaOpciones; //prueba
        bool enCombate = false;
        bool turnoJugador = true;
        Texture* texturaBackground;
        Sprite* spriteCombate;
        int opcion;
        Event* evento1;
        estadosB estadosBotones = estadosB::menu;
        RenderWindow* ventana;
        
        Font* fontMensaje;
        Text mensaje;
        
        bool useSpell = false;
        Spell hechizoUsado;

    public:
        Combat();
        Combat( RenderWindow& ventana, Player& player, Enemy& enemy );

        bool isOver( ){ return enCombate; }
        void startCombat(){ enCombate = true; };
        bool whoWon();


        //Fase Prueba
        //TODO: Acomodar y Actualizar: 
        void iniciarRectangulos();   //1
        void renderPanelOpciones(); //1
        void renderizarCombate(); //1
        void procesarLogicaCombate(); //1
        void procesarEventosCombate(); //1
        void dibujarMenuPrincipal(); //1
        void dibujarInventario(); //1
        void dibujarMenuHabilidades(); //1
        void iniciarComponentesCombate();
        void dibujarMensaje( int personaje );
        void dibujarMensaje( int personaje, int opcion);

        void useAttackSpell( Spell &hechizoUsado );
        void useSpecialAttackSpell( Spell &hechizoUsado );
        void attackPlayer();
        bool checkVictory();
        bool checkDefeat();
        bool tryEscape();

        void renderPlayer();
};


#endif
