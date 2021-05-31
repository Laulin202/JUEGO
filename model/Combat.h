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

        /*
        * isOver
        * 
        * It checks if the combat is over
        * 
        * @returns enCombate : attribute that is set to false when player or enemy dies
        */
        bool isOver( ){ return enCombate; }

        /*
        * startCombat
        * Sets the attribute in enCombate to true
        */
        void startCombat(){ enCombate = true; }
        //bool win(){ return win; }

        //Use of potions
        /*
        * usePotionCombat
        * 
        * Applies the effects of the selected potion to the player
        * 
        * @param effectValue : how much the attribute will increase.
        * @param effectType : the attribute to be affected. (this is an enum)
        * @param duration : the duration in turns the effect will affect the player
        * 
        */
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

        /*
        * useAttackSpell
        * 
        * Attacks the enemy with the selected spell
        * 
        * @param hechizoUsado is the spell selected by the player
        */
        void useAttackSpell( Spell &hechizoUsado );

        /*
        * useAttackSpell
        * 
        * Attacks the enemy with the selected spell (in this case the special spell)
        * 
        * @param hechizoUsado is the spell selected by the player
        */
        void useSpecialAttackSpell( Spell &hechizoUsado );

        /*
        * attackPlayer
        * 
        * Attacks the player with a random selected spell from the enemy
        * 
        */
        void attackPlayer();

        /*
        * checkVictory
        * 
        * Checks if the enemy is dead.
        * 
        * @return true if enemy is dead, false otherwise.
        */
        bool checkVictory();

        /*
        * checkDefeat
        *
        *  Checks if the player is dead.
        * 
        * @return true is player is dead, false otherwise.
        */
        bool checkDefeat();

        /*
        * truEscape
        *
        * The player tries to escape (depends of random numbers)
        * 
        * @return true if player is able to escape, false otherwise.
        */
        bool tryEscape();

        void renderPlayer();
        void renderEnemy();
};


#endif
