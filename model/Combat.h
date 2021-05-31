#ifndef COMBAT_H
#define COMBAT_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include "Boss.h"
#include "Spell.h"
#include "Potion.h"
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

const int MAX_POTIONS = 4;

enum estadosB{ atacar, escapar, inventario, menu };

enum{
    PLAYERWON = true, ENEMYWON = false
};


class Combat
{
    private:
        Player* player;
        Enemy * enemy;
        Clock* clock;
        int turn;
        bool win = false;
        
        //Pociones
        bool usedPotion[ MAX_POTIONS ] = {false};
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
        bool usePotion = false;
        Spell hechizoUsado;

    public:
        Combat();
        Combat( RenderWindow& ventana, Player& player, Enemy& enemy );

        bool isOver( ){ return enCombate; }
        void startCombat(){ enCombate = true; }
        //bool win(){ return win; }

        //Use of potions
        void usePotionCombat( int effectValue, int effectType, int duration );

        //Fase Prueba
        //TODO: Acomodar y Actualizar: 
        void iniciarRectangulos();   
        void renderPanelOpciones(); 
        void renderizarCombate(); 
        void procesarLogicaCombate(); 
        void procesarEventosCombate(); 
        void dibujarMenuPrincipal(); 
        void dibujarInventario(); 
        void dibujarMenuHabilidades(); 
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
        void renderEnemy();
};


#endif
