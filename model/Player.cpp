#include "Player.h"


//0 izquierda, 2 arriba, 3 abajo, 1 derecha
const int DERECHA = 1;
const int IZQUIERDA = 0; 
const int ARRIBA = 2;
const int ABAJO =3;


Player::Player(RenderWindow& ventana, int claseSprite, int cantX, int cantY, Vector2i frameActual, Vector2f originPos)
{
     /*
        Initialize the player
        Name : Hertz
        health points = 10
        attack points = 3
        Level 1 / Xp 0
     */
     this->name = "Hertz";
     this->healthPoints = 20;
     this->attackPoints = 3;
     this->lvl = 1;
     this->xp = 0;
     this->mana = 3;
     //Fase prueba

    this->nextPosition.left = getHitBox().left;
    this->nextPosition.top = getHitBox().top;
    this->nextPosition.width = getHitBox().width;
    this->nextPosition.height = getHitBox().height;

    this->posicionJugador = originPos;
    setSprite(claseSprite, cantX, cantY, frameActual, originPos);
    this->velCaminar = 10;
    this->velCorrer = 64;
    this->ventana = &ventana;

     //prueba 
    this->hechizos.push_back( Spell( "Ataque basico!", "", this->attackPoints, 0 ) );
    this->hechizos.push_back( Spell( "Bola de fuego", "Lanza una bola de fuego", (2 * this->lvl), this->lvl ) );
    this->hechizos.push_back( Spell( "Impak-trueno", "Pikazhu time", (4 * this->lvl), this->mana ) );
    this->hechizos.push_back( Spell( "Cum de Yummi", "UwU", this->lvl, 0 ) ); 

     //Prueba combate - Pendiente actualizar
    setSpriteCombate(133, 6, 1, Vector2i(0,0));


    
    //Prueba item
    Item* item1;
    item1 = new Item(true, 0);
    addItem(item1);
    
     
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


//permite actualizar fisicas del player para que no se teletransporte
void Player::checkCollisionDirection(){
    switch( direccionJ1 ){
        case arriba:
            setCTop(true);
            break;
        case abajo:
            setCBot(true);
            break;
        case izquierda:
            setCLeft(true);
            break;
        case derecha:
            setCRight(true);
            break;
    }
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

//0 izquierda, 2 arriba, 3 abajo, 1 derecha

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

    if( keyboard->teclasJugador[IZQUIERDA] && !cLeft){
        cRight = false;
        walking = true;
        if( keyboard->teclasJugador[ARRIBA]) {
            setDireccion(arribaIzquierda);
        }
        else if( keyboard->teclasJugador[ABAJO] ){
            setDireccion(abajoIzquierda);
        }
        else{
            setDireccion(izquierda);
        }
    }
    else if( keyboard->teclasJugador[DERECHA] && !cRight ){
        cLeft = false;
        walking = true;

        if( keyboard->teclasJugador[ARRIBA] ){
            setDireccion(arribaDerecha);
        }
        else if( keyboard->teclasJugador[ABAJO] ){
            setDireccion(abajoDerecha);
        }
        else{
            setDireccion(derecha);
        }
    }
    else if( keyboard->teclasJugador[ARRIBA] && !cTop){
        cBot = false;
        walking = true;
        setDireccion(arriba);
    }
    else if( keyboard->teclasJugador[ABAJO] && !cBot){
        cTop = false;
        walking = true;
        setDireccion(abajo);
    }

    //actualizo el jugador, recordemos que esta funcion llama a setTranlation evaluando si el personaje esta caminando o no

    updateFisicaJ1();

    // Si esta caminando selecciona la velocidad dependiend ode la direccion que quiere porque dependiendo de la posicion, la posicion en x y y debe cambiar y el frame tambien y entonces vos encontras un if que si esta caminando  
}



void Player::addItem( Item* item){
    inventory.addItem(*item);
}

void Player::deleteItem(int op){
    inventory.removeItemByPosition(op);
}



