#include "Player.h"

Player::Player(RenderWindow& ventana, int claseSprite, int cantX, int cantY, Vector2i frameActual)
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

     //Fase prueba
     setSprite(claseSprite, cantX, cantY, frameActual);
     this->velCaminar = 1;
     this->velCorrer = 64;
     this->ventana = &ventana;
     spritesPlayer->setColor( Color::Blue );
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

//permite actualizar fisicas del player para que no se teletrnsporte
void Player::updateFisicaJ1(){ 

    if(walking){
        selecionarVelocidad();
        setTraslation(velocidad);
    }

    else{

        setFrameX(0);

    }
}

//Permite ajustar la velocidad dependiendo las direcciones que tengamos
void Player::selecionarVelocidad(){
    switch (direccionJ1)
    {
    case arriba:
        velocidad = Vector2f( 0, -velCaminar); //estoy disminuyendo el valor en y, recordemos que velocidad es un vector
        setFrameY(3);
        break;
    
    case abajo:
        velocidad = Vector2f( 0, velCaminar );
        setFrameY(0);
        break;
    
    case izquierda:
        velocidad = Vector2f( -velCaminar,0 );
        setFrameY(1);
        break;

    case derecha:
        velocidad = Vector2f( velCaminar, 0 );
        setFrameY(2);
        break;

    case arribaIzquierda:
        velocidad = Vector2f( -velCaminar, -velCaminar );
        setFrameY(3);
        break;

    case abajoIzquierda:
        velocidad = Vector2f( -velCaminar, velCaminar );
        setFrameY(0);
        break;

    case arribaDerecha:
        velocidad = Vector2f( velCaminar, -velCaminar );
        setFrameY(3);
        break;

    case abajoDerecha:
        velocidad = Vector2f( velCaminar, velCaminar );
        setFrameY(0);
        break;
    
    default:
        break;
    }
}

void Player::procesarEventos(){


    while(ventana->pollEvent(*keyboard->evento)){
        keyboard->procesarEventos();
    }
    //0 izquierda, 2 arriba, 3 abajo, 1 derecha
    walking = false; //el jugador no esta caminando

    if( keyboard->teclasJugador[0]){

        walking = true;
        if( keyboard->teclasJugador[2]) {
            setDireccion(arribaIzquierda);
        }
        else if( keyboard->teclasJugador[3] ){
            setDireccion(abajoIzquierda);
        }
        else{
            setDireccion(izquierda);
        }
    }
    else if( keyboard->teclasJugador[1] ){
        walking = true;

        if( keyboard->teclasJugador[2] ){
            setDireccion(arribaDerecha);
        }
        else if( keyboard->teclasJugador[3] ){
            setDireccion(abajoDerecha);
        }
        else{
            setDireccion(derecha);
        }
    }
    else if( keyboard->teclasJugador[2]){
        walking = true;
        setDireccion(arriba);
    }
    else if( keyboard->teclasJugador[3]){
        walking = true;
        setDireccion(abajo);
    }

    //actualizo el jugador, recordemos que esta funcion llama a setTranlation evaluando si el personaje esta caminando o no

    updateFisicaJ1();

    // Si esta caminando selecciona la velocidad dependiend ode la direccion que quiere porque dependiendo de la posicion, la posicion en x y y debe cambiar y el frame tambien y entonces vos encontras un if que si esta caminando  
}


