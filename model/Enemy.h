#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"


class Enemy : public Entity{
    protected:
        //Item drop;
        Vector2f posicionEnemigo;
    public:
      Enemy(int claseSprite, int cantX, int cantY, Vector2i frameActual );
      Sprite getSprite(){ return *spritesPlayer; } //Me va a retornar el sprite del enemiwo
      Vector2f getPos(){ return posicionEnemigo; } //Me va a devolver la posicion del jugador
};

#endif