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
        int hearts;
        Vector2f posicionJugador; //Es la posicion del jugador, no del sprite
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

        //FASE PRUEBA
        Spell hechizo1;



    public:
        Player(RenderWindow& ventana, int claseSprite, int cantX, int cantY, Vector2i frameActual );

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
        void setTraslation( Vector2f traslation ){ posicionJugador += traslation; spritesPlayer->setPosition(posicionJugador); hitBox = spritesPlayer->getGlobalBounds(); } //el setPosition del sprite necesita un vector2
        void setVelocidad( Vector2f vel ){ velocidad = vel; }

        //propias
        void setVelCaminar( float celCaminar){  this->velCaminar = celCaminar; }
        float getVelCaminar(){ return velCaminar; }
        void setVelCorrer(float velCorrer ){  this->velCorrer = velCorrer; }
        float getVelCorrer(){  return velCorrer; }
        void setDireccion(direcciones direccionJ1){ this->direccionJ1 = direccionJ1;}

        //prueba
        Spell getSpell(){ return hechizo1; }
        
};

#endif