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
        bool usedPotion[ MAX_POTIONS ] = {false};
        list<Button> listaOpciones; 
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

        /*
        Nombre: renderizarCombate
        Output: N/A
        Input: N/A
        Funcion: renderiza todo lo necesario para que el escenario de combate se quede constante (jugador, enemigo, panel de opciones)
        */
        void renderizarCombate(); 

        /*
        Nombre: procesarLogicaCombate
        Output: N/A
        Input: N/A
        Funcion: llama a la funcion para procesar los eventos que esten sucediendo y posteriormente chequea los resultados de un turno para terinar o continuar el combate
        */
        void procesarLogicaCombate(); 

        /*
        Nombre: procesarEventosCombate
        Output: N/A
        Input: N/A
        Funcion: evalua que boton ha sido seleccionado para decidir que hacer con el turno usado
        */
        void procesarEventosCombate(); 

        /*
        Nombre: dibujarMenuPrincipal
        Output: N/A
        Input: N/A
        Funcion: dibuja el menu con las opcciones principales (atacar, posiones, escapar)
        */
        void dibujarMenuPrincipal(); 

        /*
        Nombre: dibujarInventario
        Output: N/A
        Input: N/A
        Funcion: dibuja el inventario de posiones
        */
        void dibujarInventario(); 

        /*
        Nombre: dibujarMenuHabilidades
        Output: N/A
        Input: N/A
        Funcion: dibuja el menu de habilidades (las 4 habilidades)
        */
        void dibujarMenuHabilidades(); 

        /*
        Nombre: inicarComponentesCombate
        Output: N/A
        Input: N/A
        Funcion: Incializa todo lo relacionado al fondo, las fuentes de mensajes, 
        */
        void iniciarComponentesCombate();

        /*
        Nombre: dibujarMensaje
        Output: N/A
        Input:  personaje (JUGADOR, ENEMIGO)
        Funcion: dibuja el mensaje correspondiente al personaje
        */
        void dibujarMensaje( int personaje );

        /*
        Nombre: dibujarMensaje
        Output: N/A
        Input:  personaje( JUGADOR ENEMIGO), y opcion (ESCAPO, NO_ESCAPO)
        Funcion: dibuja el mensaje del player a la hora de escapar 
        */
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

        /*
        Nombre: renderPlayer
        Output: N/A
        Input: N/A
        Funcion: permite que player llame a su funcion de renderizar 
        */
        void renderPlayer();

        /*
        Nombre: renderEnemy
        Output: N/A
        Input: N/A
        Funcion: permite que el enemigo llame a su funcion de renderizar 
        */
        void renderEnemy();
};


#endif
