#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"


class Enemy : public Entity{
    protected:
        //Item drop;
        Vector2f posicionEnemigo;
    public:
      Enemy(int claseSprite, int cantX, int cantY, Vector2i frameActual, Vector2f pos );
      Sprite getSprite(){ return *spritesPlayer; } //Me va a retornar el sprite del enemiwo
      Vector2f getPos(){ return posicionEnemigo; } //Me va a devolver la posicion del enemiwowo
      FloatRect getBox(){ return spritesPlayer->getGlobalBounds(); } //Me va a devolver el cuadrado del enemiwowowo
      void setHealthPoints( int newHP ){ this->healthPoints = newHP; }
      int getHealthPoints( ){ return this->healthPoints; }
      int getAttackDamage( ){ return this->attackPoints; }
};

#endif