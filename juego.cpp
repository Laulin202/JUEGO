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
    ventana->draw(j1->getSprite());
    ventana->draw(e1->getSprite());
    ventana->display();
}

void Juego::iniciar(){
    j1 = new Player(*ventana,12, 4, 4, Vector2i(2,1));
    e1 = new Enemy(420, 1, 1, Vector2i(0,0));
    fps = 60; // 60 Frames x Seconds
    reloj1 = new Clock();
    cronometro1 = new Time(); 

}


bool Juego::enemyCollision( Vector2f playerPosition, Vector2f enemyPosition )
{
  float xDif = abs(playerPosition.x - enemyPosition.x);
  float yDif = abs(playerPosition.y - enemyPosition.y);

  if( xDif <= ATTACK_DISTANCE && yDif <= ATTACK_DISTANCE ){
    return true;
  }
  return false;
}

