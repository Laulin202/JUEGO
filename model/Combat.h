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

        bool isOver( ){ return enCombate; } //
        void startCombat(){ enCombate = true; } //
        void usePotionCombat( int effectValue, int effectType, int duration ); //

        /*
        Nombre: iniciarRectangulos
        Output: N/A
        Input: N/A
        Funcion: Incializa todo el contenido de los botones (rectangulo, id, position, textura) de la escena de combate
        */
        void iniciarRectangulos();  

        /*
        Nombre: renderPanelOpciones
        Output: N/A
        Input: N/A
        Funcion: renderiza los botones y mensajes correspondientes dependiendo la accion que desee hacer el jugador
        */ 
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

        void useAttackSpell( Spell &hechizoUsado );
        void useSpecialAttackSpell( Spell &hechizoUsado );
        void attackPlayer();
        bool checkVictory();
        bool checkDefeat();
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
