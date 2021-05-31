#include "Enemy.h"

Enemy::Enemy(string name, int health, int attack, int claseSprite, int cantX, int cantY, Vector2i frameActual, Vector2f pos, string spell1, string spell2, Vector2f scale, bool protector)
{
     /*
        Initialize the player
        Name : Hertz
        health points = 10
        attack points = 3
        Level 1 / Xp 0
     */
   this->protector = protector;
   this->posicionEnemigo = pos;
   this->name = name;
   this->maxHealthPoints = health;
   this->healthPoints = maxHealthPoints;
   this->attackPoints = attack;
   this->lvl = 1;
   this->spell1 = spell1;
   this->spell2 = spell2;

   //Fase prueba UwU
   setSprite(claseSprite, cantX, cantY, frameActual, pos);
   setSpriteCombate(claseSprite, cantX, cantY, frameActual, scale);
}

Enemy::~Enemy(){
   
}