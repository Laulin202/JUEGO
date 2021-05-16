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
    texturesPlayer = new Texture[12];    //atributos de player
    spritesPlayer = new Sprite[12];      //atributos de player

    for(int i = 0; i < 12; i++){
        if (!texturesPlayer[i].loadFromFile("src/images/player/" + std::__cxx11::to_string(i) + ".png"))
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
    /*
        while( i < 12){
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
    */
    //asi inicia el jugador
   i = playerMovement( ventanaJuego );
   ventanaJuego->clear(sf::Color::Black);
   ventanaJuego->draw(spritesPlayer[i]);
   ventanaJuego->display();

   

}

bool Player::spritesTime(Time elapsed1){
    if( elapsed1.asSeconds() >= 0.1f ){
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

int Player::playerMovement( RenderWindow* ventanaJuego ){
    Vector2f position;
    Clock clock;
    Time timeElapsed;
    int i;

    while(Keyboard::isKeyPressed(Keyboard::Left)){
            i = 3;
            while(i < i + 3){
                spritesPlayer[i].move(-10.f, 0.f);
                if (spritesTime( timeElapsed )){
                ventanaJuego->draw(spritesPlayer[i]);
                ventanaJuego->display();
                clock.restart();
                position = spritesPlayer[i].getPosition();
                playerUpdatePosition(position);
                i++;
                }
            }
    } 
    
    if(Keyboard::isKeyPressed(Keyboard::Right)){
            spritesPlayer[i].move(10.f, 0.f);
    } 
    if(Keyboard::isKeyPressed(Keyboard::Up)){
            spritesPlayer[i].move(0.f, -10.f);
    }
    if(Keyboard::isKeyPressed(Keyboard::Down)){
            spritesPlayer[i].move(0.f, 10.f);
    }
    
    /*position = spritesPlayer[i].getPosition();
    playerUpdatePosition(position);*/

    return i;
}

void Player::playerUpdatePosition(Vector2f pos){
    for(int i = 0; i < 12; i++){
        spritesPlayer[i].setPosition(pos);
    }
}