#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"
#include "Teclado.h"
#include "Spell.h"

#include "Item.h"
#include "Inventory.h"
#include "Potion.h"


//fase prueba



#include <map>
using std::map;

enum estados{ idle, walking, runnig, death};
enum direcciones{ arriba , arribaIzquierda, arribaDerecha, abajo, abajoIzquierda, abajoDerecha, izquierda, derecha};

class Player : public Entity{
    private:
        //For potion effects
        int increaseAttackPoints; //For basic attacks and spells
        int increaseAttackPointsDuration;
        int maxMana;
        int hearts;

        Vector2f posicionJugador; //Es la posicion del jugador, no del sprite
        Vector2f previousPosition;
        Inventory* inventory; //Invetario del jugador, es un objeto de clase Inventory
        int mana;
        int xp;
        int resistancePoints;
        Vector2f velocidad; //Velocidad actual
        float velCaminar; //velocidad al caminar
        float velCorrer; //velocidad al correr
        direcciones direccionJ1 = abajo; //direccion a la que mira el player
        Teclado* keyboard = Teclado::getTeclado();  //este onjeto me permite manejar en su mayoria lo que suceda con el teclado (privado)
        RenderWindow* ventana;   //Basicamente el jugador con la ventana podra mostrarse sin depender estrictamente de que lo llamen en juego
        bool cTop = false, cBot = false, cLeft = false, cRight = false;
        vector<Spell> hechizos;

        //Elementos graficos complementarios del Jugador en combate
        RectangleShape corazonImg;
        RectangleShape manaImg;
        Texture* textureCorazon;
        Texture* textureMana;
        Font* fontMensaje;
        Text mensajeVida;
        Text mensajeMana;

    public:
        Player(RenderWindow& ventana, int claseSprite, int cantX, int cantY, Vector2i frameActual, Vector2f originPos = Vector2f(500, 500) );

        //Atributo
        bool walking = false;
        
        /*
        Nombre: updateHealthPoints
        Output:
        Input:
        Funcion:
        */
        void updateHealthPoints( int newHealthPoints );

        /*
        Nombre:
        Output:
        Input:
        Funcion:
        */
        void updateAttackPoints( int newAttackPoints );

        /*
        Nombre:
        Output:
        Input:
        Funcion:
        */
        bool checkDead( );

        /*
        Nombre:
        Output:
        Input:
        Funcion:
        */
        bool checkGameOver( );

        /*
        Nombre: updateFisicaJ1
        Output: N/A
        Input: N/A
        Funcion: me evalua si el jugador esta caminando o no para saber si se debe atualizar su movimiento
        */
        void updateFisicaJ1(); 

        /*
        Nombre: seleccionarVelocidad
        Output: N/A
        Input: N/A
        Funcion: dependiendo a que direccion este mirando el jugador, me seleccionara el vector con valores x,y correspondiente
        */ 
        void selecionarVelocidad();

        /*
        Nombre: procesarEventos
        Output: N/A
        Input: N/A
        Funcion: evalua que elemento del vector de teclas es verdadero para seleccionar la direccion correspondiente
        */
        void procesarEventos();

        /*
        Nombre:
        Output:
        Input:
        Funcion:
        */
        void checkCollisionDirection();

        /*
        Nombre:
        Output:
        Input:
        Funcion:
        */
        void restoreHealthPoints( int health );

        /*
        Nombre:
        Output:
        Input:
        Funcion:
        */
        void restoreMana( int mana );

        /*
        Nombre: addItem
        Output: puntero de tipo Item
        Input: N/A
        Funcion: le envia el intem al attributo inventario
        */
        void addItem( Item* item );

        /*
        Nombre: deleteItem
        Output:
        Input:
        Funcion:
        */
        void deleteItem(int op);

        /*
        Nombre: renderAttribues
        Output: N/A
        Input: N/A
        Funcion: me renderiza los atributos graficos complementarios del juegador en combate
        */
        void renderAttributes();

        /*
        Nombre: loadAttributesCombat
        Output: N/A
        Input: N/A
        Funcion: Me carga las las texturas, y me ajusta las posiciones de los sprites y mensajes que vida y mana mostrados en combate.
        */
        void loadAttributesCombat();

        /*
        Nombre: resetMovement
        Output: N/A
        Input: N/A
        Funcion: llama al atributo tipoTeclado para actualizar el vector de teclas.
        */
        void resetMovement(){ keyboard->updateKeys(); };


        //Setters

        void setPos(Vector2f posicion){ posicionJugador = posicion; spritesPlayer->setPosition(posicionJugador); hitBox = spritesPlayer->getGlobalBounds(); } //Me actualiza la posicion del jugador, y con ella la posicion de sus sprites y hitbox.
        void setTraslation( Vector2f traslation ){ previousPosition = posicionJugador; posicionJugador += traslation; spritesPlayer->setPosition(posicionJugador); hitBox = spritesPlayer->getGlobalBounds(); rectangle->setPosition(posicionJugador); } //el funcionamiento es parecido al setPos, solo que este me permite dar un movimiento constante por la pantalla
        void setVelocidad( Vector2f vel ){ velocidad = vel; } // me actualiza la velocidad general del player
        void setHealthPoints( int newHealthPoints ){ this->healthPoints = newHealthPoints; } //Me actualiza los puntos de vida del PLayer
        void setMana( int newMana ){ this->mana = newMana; } //Me actualiza los puntos de mana del player
        void setCTop(bool value){ cTop = value;} 
        void setCBot(bool value){ cBot = value;}
        void setCLeft(bool value){ cLeft = value;}
        void setCRight(bool value){ cRight = value;}
        void setIncreaseAttackPoints( int increaseAttackPoints ){ this->increaseAttackPoints = increaseAttackPoints; }
        void setIncreaseAttackPointsDuration( int duration ){ this->increaseAttackPointsDuration = duration; }
        void setVelCaminar( float celCaminar){  this->velCaminar = celCaminar; } // actualiza la velocidad al caminar
        void setVelCorrer(float velCorrer ){  this->velCorrer = velCorrer; } // actualiza la velocidad al correr
        void setDireccion(direcciones direccionJ1){ this->direccionJ1 = direccionJ1;} // actualiza la direccion del player dependiendo el enum que reciba

        //Getters
        Vector2f getPreviousPosition(){ return previousPosition; } //retorna 
        float getVelCaminar(){ return velCaminar; } //retorna la velocidad al caminar
        float getVelCorrer(){  return velCorrer; } //retorna la velocidad al correr
        int getAttackDamage(){ return this->attackPoints; } //retorna los attackPoints del player
        int getMaxMana(){ return this->maxMana; } //retorna el mana maximo
        int getHealthPoints(){ return this->healthPoints; } //retorna los puntos de vida
        int getMana(){ return this->mana; } //retorna el mana
        int getIncreaseAttackPoints( ){ return this->increaseAttackPoints; } //retorna 
        int getIncreaseAttackPointsDuration( ){ return this->increaseAttackPointsDuration; } //retorna
        Potion& getPotion(int op); //retorna la pocion correspondiente al indice recibido
        Spell getSpell( int spellIndex ){ return this->hechizos[ spellIndex ]; } //retorna la habilidad dependiendo el indice
        Sprite getSprite(){ return *spritesPlayer; } //retorna el sprite del jugador
        Vector2f getPos(){ return posicionJugador; }  //retorna la posicin del jugador

        

        
};

#endif