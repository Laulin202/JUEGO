#include "Enemy.h"

Enemy::Enemy(int claseSprite, int cantX, int cantY, Vector2i frameActual, Vector2f pos)
{
     /*
        Initialize the player
        Name : Hertz
        health points = 10
        attack points = 3
        Level 1 / Xp 0
     */
     this->posicionEnemigo = pos;
     this->name = "El Diavlo";
     this->healthPoints = 9;
     this->attackPoints = 1;
     this->lvl = 1;

     //Fase prueba UwU
     setSprite(claseSprite, cantX, cantY, frameActual, pos);

}