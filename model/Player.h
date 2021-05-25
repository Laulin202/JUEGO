#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"
#include "Teclado.h"
#include "Spell.h"
//fase prueba



#include <map>
using std::map;

enum estados{ idle, walking, runnig, death};
enum direcciones{ arriba , arribaIzquierda, arribaDerecha, abajo, abajoIzquierda, abajoDerecha, izquierda, derecha};

class Player : public Entity{
    private:
        int maxHealthPoints;
        int maxMana;
        int hearts;
        Vector2f posicionJugador; //Es la posicion del jugador, no del sprite
        FloatRect nextPosition;
        //vector<Item> inventory;
        //map<string, Equipment> equipment;
        int mana;
        int xp;
        int resistancePoints;
        Vector2f velocidad; //Velocidad actual
        float velCaminar; //velocidad al caminar
        float velCorrer; //velocidad al correr
        direcciones direccionJ1 = abajo; //direccion a la que mira el player
        Teclado* keyboard = Teclado::getTeclado();  //este onjeto me permite manejar en su mayoria lo que suceda con el teclado
        RenderWindow* ventana;   //Basicamente el jugador con la ventana podra mostrarse sin depender estrictamente de que lo llamen en juego
        bool cTop = false, cBot = false, cLeft = false, cRight = false;

        //FASE PRUEBA
        vector<Spell> hechizos;

    public:
        Player(RenderWindow& ventana, int claseSprite, int cantX, int cantY, Vector2i frameActual, Vector2f originPos = Vector2f(500, 500) );

        //atributo de prueba en publico(pendiente optimizar)
        bool walking = false;
        
        void updateHealthPoints( int newHealthPoints );
        void updateAttackPoints( int newAttackPoints );
        bool checkDead( );
        bool checkGameOver( );
        

        
        Sprite getSprite(){ return *spritesPlayer; } //Me va a retornar el sprite del jugador 
        Vector2f getPos(){ return posicionJugador; } //Me va a devolver la posicion del jugador
        void updateFisicaJ1();  //Actualiza el movimiento "fisicas" del jugador
        void selecionarVelocidad();
        void procesarEventos();


        void setPos(Vector2f posicion){ posicionJugador = posicion; spritesPlayer->setPosition(posicionJugador); } //SpriteJugador va a buscar a SpritePlayer, y ese sera el que se actualice con la nueva posicicon
        void setTraslation( Vector2f traslation ){ posicionJugador += traslation; spritesPlayer->setPosition(posicionJugador); hitBox = spritesPlayer->getGlobalBounds(); rectangle->setPosition(posicionJugador); } //el setPosition del sprite necesita un vector2
        void setVelocidad( Vector2f vel ){ velocidad = vel; }
        FloatRect getNextPosition(){ nextPosition.left = getHitBox().left + velCaminar; nextPosition.top = getHitBox().top + velCaminar; return nextPosition; }

        //propias
        void setVelCaminar( float celCaminar){  this->velCaminar = celCaminar; }
        float getVelCaminar(){ return velCaminar; }
        void setVelCorrer(float velCorrer ){  this->velCorrer = velCorrer; }
        float getVelCorrer(){  return velCorrer; }
        void setDireccion(direcciones direccionJ1){ this->direccionJ1 = direccionJ1;}
        void checkCollisionDirection();

        void setCTop(bool value){ cTop = value;}
        void setCBot(bool value){ cBot = value;}
        void setCLeft(bool value){ cLeft = value;}
        void setCRight(bool value){ cRight = value;}

        //prueba
        Spell getSpell( int spellIndex ){ return this->hechizos[ spellIndex ]; }
        void setHealthPoints( int newHealthPoints ){ this->healthPoints = newHealthPoints; }
        void setMana( int newMana ){ this->mana = newMana; }
        int getAttackDamage(){ return this->attackPoints; }
        int getMaxHealthPoints(){ return this->maxHealthPoints; }
        int getMaxMana(){ return this->maxMana; }
        int getHealthPoints(){ return this->healthPoints; }
        int getMana(){ return this->mana; }
        
};

#endif