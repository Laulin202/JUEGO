#include "juego.h"

const int ATTACK_DISTANCE = 15;

Juego::Juego(Vector2u resolucion){
    ventana = new RenderWindow(VideoMode(resolucion.x, resolucion.y), "Videojuego Prueba  2D");
    iniciar();

    //mientras que gameover no sea verdadero me haga el game loop
    gameLoop();
}


//este mantiene la ventana mostrandose, procesando eventos y animando al personaje en caso de
void Juego::gameLoop(){

    while(!gameOver){

        *cronometro1 = reloj1->getElapsedTime(); //Tiempo transcurrido
        if(cronometro1->asSeconds() > 1 / fps){ //un frame cada 0,016 milisegundos
        

            procesarLogica();

            if(j1->walking){
                j1->animarFrame();
            }
            else{  
            }
            renderizar();
            reloj1->restart();
            
        }
    }

}

void Juego::procesarLogica(){
    j1->procesarEventos();
    if( enemyCollision( j1->getPos(), e1->getPos() )){
      std::cout << "Colizion magica UwU\n";
    }
}

void Juego::renderizar(){
    ventana->clear();
    ventana->draw(*map);
    ventana->draw(j1->getSprite());
    ventana->draw(e1->getSprite());
    ventana->display();
}

void Juego::iniciar(){
    j1 = new Player(*ventana,12, 4, 4, Vector2i(2,1));
    e1 = new Enemy(420, 1, 1, Vector2i(0,0), Vector2f(-50,-50));
    tileset = new Texture();
    tileset->loadFromFile("src/images/tileset/tileset.png");
    map = new TileMap(tileset, 80, 60, 48.0f, 40.0f);
    fps = 60; // 60 Frames x Seconds
    reloj1 = new Clock();
    cronometro1 = new Time(); 

}


bool Juego::enemyCollision( Vector2f playerPosition, Vector2f enemyPosition ){
    Vector2f frameSize = e1->getFrameSize();
    //float midX = (e1->getBox().getPosition().x)/2;
    //float midY = (e1->getBox().getPosition().y)/2;
    float xDif = abs(playerPosition.x - enemyPosition.x - (frameSize.x/2) );
    float yDif = abs(playerPosition.y - enemyPosition.y - /frameSize.y/2);

    if( xDif <= ATTACK_DISTANCE && yDif <= ATTACK_DISTANCE ){
        return true;
    }
    return false;
}

