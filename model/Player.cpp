#include "Player.h"


//0 izquierda, 2 arriba, 3 abajo, 1 derecha
const int DERECHA = 1;
const int IZQUIERDA = 0; 
const int ARRIBA = 2;
const int ABAJO =3;


Player::Player(RenderWindow& ventana, int claseSprite, int cantX, int cantY, Vector2i frameActual, Vector2f originPos)
{

    //iniciamos atributos basicos de Herz
     this->name = "Hertz";
     this->maxHealthPoints = 100;
     this->increaseAttackPoints = 0;
     this->increaseAttackPointsDuration = 0;
     this->healthPoints = maxHealthPoints;
     this->attackPoints = 10;
     this->lvl = 1;
     this->xp = 0;
     this->mana = 10;

    this->posicionJugador = originPos;
    setSprite(claseSprite, cantX, cantY, frameActual, originPos);
    this->velCaminar = 5;
    this->velCorrer = 64;
    this->ventana = &ventana;

    this->hechizos.push_back( Spell( "Ataque basico!", "", this->attackPoints, 0 ) );
    this->hechizos.push_back( Spell( "Bola de fuego", "Lanza una bola de fuego", (10 * this->lvl), this->lvl ) );
    this->hechizos.push_back( Spell( "Impak-trueno", "Pikazhu time", (15 * this->lvl), (int)this->mana/2 ) );
    this->hechizos.push_back( Spell( "Cum de Yummi", "UwU", this->lvl, 1 ) ); 

    setSpriteCombate(133, 6, 1, Vector2i(0,0));

    //Inventario
    inventory = new Inventory();
    
    /*
    string potionName = "Castlevania";
    string potionDesc = "Cura para el insomnio";
    int potionType = restoreHealthPointsE;
    int potionValue = 200;
    int potionDuration = 5;
    Potion* potion1;
    potion1 = new Potion(potionName, potionDesc, 1, potionValue, potionType, potionDuration, Vector2f(100,100));
    addItem(potion1);
    */
     
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
    inventory->addItem(item);
}

void Player::deleteItem(int op){
    inventory->removeItemByPosition(op);
}

//Restore mana and restore health
void Player::restoreHealthPoints( int health ){
  if( this->healthPoints + health > this->maxHealthPoints ){
    this->healthPoints = maxHealthPoints;
  }else{
    this->healthPoints += health;
  }
}
void Player::restoreMana( int mana ){
  if( this->mana + mana > this->maxMana ){
    this->mana = maxMana;
  }else{
    this->mana += mana;
  }
}

Potion& Player::getPotion(int op){
    Potion *potion = dynamic_cast<Potion*>( inventory->getItemByPosition(op) );
    Potion *noPotion = NULL;
    if(potion->getIsPotion()){
        return *potion;
    }
    return *noPotion;
}

void Player::loadAttributesCombat(){


    //Se inicializa todo lo relacionado al mensaje

    fontMensaje = new Font();
    if(!fontMensaje->loadFromFile("src/fonts/Lomanos.ttf")){
        cout << "Error al cargar la fuente!" << endl;
        exit(1);
    }

    mensajeVida.setFont(*fontMensaje);
    mensajeVida.setPosition(Vector2f(70,20));
    mensajeMana.setFont(*fontMensaje);
    mensajeMana.setPosition(Vector2f(70,60));

    //Se inicializa todo lo relacionado a las img de su vida y mana

    corazonImg.setSize(Vector2f(40,40));
    corazonImg.setPosition(Vector2f(30,20));
    manaImg.setSize(Vector2f(40,40));
    manaImg.setPosition(Vector2f(30,60));

    textureCorazon = new Texture();
    textureMana = new Texture();

    textureCorazon->loadFromFile("src/images/textureCombate/Corazon.png");
    textureMana->loadFromFile("src/images/textureCombate/Mana.png");

    corazonImg.setTexture(textureCorazon);
    manaImg.setTexture(textureMana);

}

void Player::renderAttributes(){
    mensajeVida.setString( " " + to_string(getHealthPoints()));
    mensajeMana.setString( " "+ to_string( getMana()));

    ventana->draw(corazonImg);
    ventana->draw(manaImg);
    ventana->draw(mensajeVida);
    ventana->draw(mensajeMana);
    
}





