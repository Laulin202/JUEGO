#include "Player.h"

 Player::Player()
 {
     /*
        Initialize the player
        Name : Hertz
        health points = 10
        attack points = 3
        Level 1 / Xp 0
     */
     this->name = "Hertz";
     this->healthPoints = 10;
     this->attackPoints = 3;
     this->lvl = 1;
     this->xp = 0;

     inicializarTexturaPlayer( );
 }

void Player::inicializarTexturaPlayer(){
    texturesPlayer = new Texture[25];    //atributos de player
    spritesPlayer = new Sprite[25];      //atributos de player

    for(int i = 0; i < 25; i++){
        if (!texturesPlayer[i].loadFromFile(std::__cxx11::to_string(i)+".png"))
        {
            cout << "No textura";
        }
        spritesPlayer[i].setTexture(texturesPlayer[i]);
        spritesPlayer[i].setOrigin( sf::Vector2f(-350.f,-200.f));
    }
}

void Player::dibujarPlayerPantalla(RenderWindow* ventanaJuego){
    Clock clock;
    Time timeElapsed;
    int i;
    i = 20;
        while( i < 23){
            ventanaJuego->clear(sf::Color::Black);
            timeElapsed = clock.getElapsedTime();
            if (spritesTime( timeElapsed )){
                ventanaJuego->draw(spritesPlayer[i]);
                playerMovement(i);
                ventanaJuego->display();
                clock.restart();
                i++;
            }
        }
}

bool Player::spritesTime(Time elapsed1){
    if( elapsed1.asSeconds() >= 0.2f ){
        return true;
    }
    return false;
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


void Player::playerMovement( int i){
    sf::Vector2f position;
    if (Keyboard::isKeyPressed(sf::Keyboard::Left)){
            // left key is pressed: move our character
            spritesPlayer[i].move(-10.f, 0.f);
    } 
    else if(Keyboard::isKeyPressed(Keyboard::Right)){
            spritesPlayer[i].move(10.f, 0.f);
    } 
    else if(Keyboard::isKeyPressed(Keyboard::Up)){
            spritesPlayer[i].move(0.f, -10.f);
    }
    else if(Keyboard::isKeyPressed(Keyboard::Down)){
            spritesPlayer[i].move(0.f, 10.f);
    }
    position = spritesPlayer[i].getPosition();
    playerUpdatePosition(position);
}

void Player::playerUpdatePosition(sf::Vector2f pos){
    for(int i = 0; i < 25; i++){
        spritesPlayer[i].setPosition(pos);
    }
}