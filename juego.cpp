#include "juego.h"

/*
TODO: Acomodar en el Repositorio Juego:
Crear Combate.cpp
Mover por completo todo lo que tienes en Combat.cpp
Ajustar Combat.h
Ajustar la condicion isOver() (no olvides el !)


*/


const int ATTACK_DISTANCE = 15;

Juego::Juego(Vector2u resolucion){
    ventana = new RenderWindow(VideoMode(resolucion.x, resolucion.y), "Videojuego Prueba  2D");
    iniciar();

    //Me permitira entrar a un Loop hasta que no termine el juego 
    gameLoop();
}


// mantiene la ventana mostrandose, procesando eventos y animando
void Juego::gameLoop(){

    while(!gameOver){

        *cronometro1 = reloj1->getElapsedTime(); //Tiempo transcurrido
        if(cronometro1->asSeconds() > 1 / fps){ //un frame cada 0,016 milisegundos
        

            if( !combatePlayer->isOver() ){

                procesarLogica();

                if(j1->walking){
                    j1->animarFrame();
                }
                renderizar();
                
            }
            else{
                combatePlayer->procesarLogicaCombate();
                combatePlayer->renderizarCombate();
            }
            
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
    tileset->loadFromFile("src/images/tileset/tileset.png"); //carga todo el png de los tiles
    map = new TileMap(tileset, 80, 60, 48.0f, 40.0f); //aqui cargaremos el mapa
    fps = 60; // 60 Frames x Seconds
    reloj1 = new Clock();
    cronometro1 = new Time(); 
    

    //Fase prueba
    combatePlayer = new Combat( *ventana, *j1, *e1 ) ;
    combatePlayer->iniciarComponentesCombate();
}

// FUNCIONES FASE PRUEBA, FALTA PASARLOS A UNA CLASE COMBATE Y AJUSTARLOS AHI





