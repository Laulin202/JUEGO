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
        Inventory* inventory;
        //map<string, Equipment> equipment;
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

        //FASE PRUEBA
        vector<Spell> hechizos;



        //FASE PRUEBA PENDIENTE REVISAR
        RectangleShape corazonImg;
        RectangleShape manaImg;
        Texture* textureCorazon;
        Texture* textureMana;
        Font* fontMensaje;
        Text mensajeVida;
        Text mensajeMana;

    public:
        Player(RenderWindow& ventana, int claseSprite, int cantX, int cantY, Vector2i frameActual, Vector2f originPos = Vector2f(500, 500) );

        //atributo de prueba en publico(pendiente optimizar)
        bool walking = false;
        
        void updateHealthPoints( int newHealthPoints );
        void updateAttackPoints( int newAttackPoints );
        bool checkDead( );
        bool checkGameOver( );

        void updateFisicaJ1();  
        void selecionarVelocidad();
        void procesarEventos();
        void checkCollisionDirection();

        
        //Setters for combat potions / Increase damage / Restore health - mana
        void restoreHealthPoints( int health );
        void restoreMana( int mana );
        
        //Getters for combat potions / Increase damage / Restore health - mana
        void addItem( Item* item );
        void deleteItem(int op);
        //FASE PRUEBA, PENDIENTE REVISAR
        void renderAttributes();
        void loadAttributesCombat();


        //Setters

        void setPos(Vector2f posicion){ posicionJugador = posicion; spritesPlayer->setPosition(posicionJugador); hitBox = spritesPlayer->getGlobalBounds(); } //SpriteJugador va a buscar a SpritePlayer, y ese sera el que se actualice con la nueva posicicon
        void setTraslation( Vector2f traslation ){ previousPosition = posicionJugador; posicionJugador += traslation; spritesPlayer->setPosition(posicionJugador); hitBox = spritesPlayer->getGlobalBounds(); rectangle->setPosition(posicionJugador); } //el setPosition del sprite necesita un vector2
        void setVelocidad( Vector2f vel ){ velocidad = vel; }
        void setHealthPoints( int newHealthPoints ){ this->healthPoints = newHealthPoints; }
        void setMana( int newMana ){ this->mana = newMana; }
        void setCTop(bool value){ cTop = value;}
        void setCBot(bool value){ cBot = value;}
        void setCLeft(bool value){ cLeft = value;}
        void setCRight(bool value){ cRight = value;}
        void setIncreaseAttackPoints( int increaseAttackPoints ){ this->increaseAttackPoints = increaseAttackPoints; }
        void setIncreaseAttackPointsDuration( int duration ){ this->increaseAttackPointsDuration = duration; }
        void setVelCaminar( float celCaminar){  this->velCaminar = celCaminar; }
        void setVelCorrer(float velCorrer ){  this->velCorrer = velCorrer; }
        void setDireccion(direcciones direccionJ1){ this->direccionJ1 = direccionJ1;}

        //Getters
        Vector2f getPreviousPosition(){ return previousPosition; }
        float getVelCaminar(){ return velCaminar; }
        float getVelCorrer(){  return velCorrer; }
        int getAttackDamage(){ return this->attackPoints; }
        int getMaxMana(){ return this->maxMana; }
        int getHealthPoints(){ return this->healthPoints; }
        int getMana(){ return this->mana; }
        int getIncreaseAttackPoints( ){ return this->increaseAttackPoints; }
        int getIncreaseAttackPointsDuration( ){ return this->increaseAttackPointsDuration; }
        Potion& getPotion(int op);
        Spell getSpell( int spellIndex ){ return this->hechizos[ spellIndex ]; }
        Sprite getSprite(){ return *spritesPlayer; }
        Vector2f getPos(){ return posicionJugador; } 

        void resetMovement(){ keyboard->updateKeys(); };

        
};

#endif