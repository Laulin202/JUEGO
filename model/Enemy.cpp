#include "Enemy.h"

Enemy::Enemy(int claseSprite, int cantX, int cantY, Vector2i frameActual, Vector2f pos, string spell1, string spell2)
{
     /*
        Initialize the player
        Name : Hertz
        health points = 10
        attack points = 3
        Level 1 / Xp 0
     */
     this->posicionEnemigo = pos;
     this->name = "Nombre Enemigo";
     this->maxHealthPoints = 50;
     this->healthPoints = maxHealthPoints;
     this->attackPoints = 10;
     this->lvl = 1;
     this->spell1 = spell1;
     this->spell2 = spell2;

     
     setSprite(claseSprite, cantX, cantY, frameActual, pos);
     setSpriteCombate(470,8,1,Vector2i(0,0));
}

Enemy::~Enemy(){
   
}