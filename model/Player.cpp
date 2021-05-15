#include "Player.h"

 Player::Player( sf::Texture *  textures, sf::Sprite * sprites )
 {
     /*
        Initialize the player
        Name : Hertz
        health points = 10
        attack points = 3
        Level 1 / Xp 0
     */
     this->textures = textures;
     this->sprites = sprites;
     this->name = "Hertz";
     this->healthPoints = 10;
     this->attackPoints = 3;
     this->lvl = 1;
     this->xp = 0;
 }
        
void Player::updateHealthPoints( int newHealthPoints )
{
    this->healthPoints = newHealthPoints;
}

void Player::updateAttackPoints( int newAttackPoints )
{
    this->attackPoints = newAttackPoints;
}

bool Player::checkDead( )
{
    if( this->healthPoints <= 0 ){
        return true;
    }
    return false;
}

bool Player::checkGameOver( )
{
    if( this->hearts <= 0 ){
        return true;
    }
    return false;
}