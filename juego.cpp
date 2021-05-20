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
    e1 = new Enemy(420, 1, 1, Vector2i(0,0), Vector2f(-150,-150));
    tileset = new Texture();
    tileset->loadFromFile("src/images/tileset/tileset.png");
    map = new TileMap(tileset, 80, 60, 48.0f, 40.0f);
    fps = 60; // 60 Frames x Seconds
    reloj1 = new Clock();
    cronometro1 = new Time(); 

}



