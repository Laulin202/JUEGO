#include "Enemy.h"

Enemy::Enemy(int claseSprite, int cantX, int cantY, Vector2i frameActual)
{
     /*
        Initialize the player
        Name : Hertz
        health points = 10
        attack points = 3
        Level 1 / Xp 0
     */
<<<<<<< HEAD
     this->posicionEnemigo.x = 0;
     this->posicionEnemigo.y = 0;
=======
>>>>>>> 78f9e794cd83803a85b1b4b6e87045a0767a11c2
     this->name = "El Diavlo";
     this->healthPoints = 420;
     this->attackPoints = 666;
     this->lvl = 44;

     //Fase prueba UwU
     setSprite(claseSprite, cantX, cantY, frameActual);

}