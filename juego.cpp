#include "juego.h"

const int ATTACK_DISTANCE = 15;

Juego::Juego(Vector2u resolucion){
    ventana = new RenderWindow(VideoMode(resolucion.x, resolucion.y), "Videojuego Prueba  2D");
    iniciar();
    iniciarView();

    //mientras que gameover no sea verdadero me haga el game loop
    gameLoop();
}


//este mantiene la ventana mostrandose, procesando eventos y animando al personaje en caso de
void Juego::gameLoop(){

    while(!gameOver){

        *cronometro1 = reloj1->getElapsedTime(); //Tiempo transcurrido
        if(cronometro1->asSeconds() > 1 / fps){ //un frame cada 0,016 milisegundos
        
            if(!paused){ //unpaused update
                procesarLogica();

                if(j1->walking){
                    j1->animarFrame();
                }
                else{  
                }
                if(j1->getHitBox().intersects(e1->getHitBox())){
                
                }
                ventana->setView(view);
                renderizar();
                reloj1->restart();
            }
            else{ //paused update

            }
        }
    }

}

void Juego::procesarLogica(){
    j1->procesarEventos();
    updateCollision();
    if(updateTileCollision()){
        j1->checkCollisionDirection();
    }
    updateView();
}

void Juego::renderizar(){
    ventana->clear();
    ventana->draw(*map);
    ventana->draw(j1->getSprite());
    ventana->draw(e1->getSprite());
    ventana->draw(j1->getRectangle());
    ventana->draw(e1->getRectangle());
    ventana->display();
}

void Juego::pause(){

}

void Juego::unpause(){

}

void Juego::updateCollision(){
    // Left Collision
    if(j1->getHitBox().left < mapBox.left){
        j1->setCLeft(true);
    }
    // Right Collision 
    else if(j1->getHitBox().left + j1->getHitBox().width >= mapBox.width){
        j1->setCRight(true);
    }
    // Top Collision
    if(j1->getHitBox().top < mapBox.top){
        j1->setCTop(true);
    } 
    // Bottom Collision
    else if(j1->getHitBox().top + j1->getHitBox().height >= mapBox.height){
        j1->setCBot(true);
    }
}

bool Juego::updateTileCollision(){
    bool collision = false;
    for(int i = 0; i < tilesArray.size(); i++){
        if(j1->getHitBox().intersects(tilesArray[i])){
            collision = true;
        }
    }
    return collision;
}

void Juego::updateView(){
    view.setCenter(j1->getPos());
}

void Juego::iniciar(){
    j1 = new Player(*ventana,12, 4, 4, Vector2i(2,1), Vector2f(ventana->getSize().x, ventana->getSize().y));
    e1 = new Enemy(420, 1, 1, Vector2i(0,0), Vector2f(300, 300));
    loadMap();
    fps = 60; // 60 Frames x Seconds
    reloj1 = new Clock();
    cronometro1 = new Time();
}

void Juego::loadMap(){
    tileset = new Texture();
    tileset->loadFromFile("src/images/tileset/tileset.png");
    map = new TileMap(tileset, 20, 20, 48.0f, 50.0f);
    mapBox = map->getArray()->getBounds();
    tilesArray = map->getTilesArray();
}

void Juego::iniciarView(){
    view.setSize( Vector2f( ventana->getSize().x, ventana->getSize().y ) );
    view.setCenter( Vector2f( ventana->getSize().x/2.f, ventana->getSize().y/2.f ) );
}



