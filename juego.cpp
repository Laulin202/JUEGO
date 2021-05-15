#include "juego.h"

Juego::Juego(int resolucion_x, int resolucion_y, string titulo){

    //Esta sera la ventana, aqui estamos definiendo su tamaño
    ventanaJuego = new RenderWindow(VideoMode(resolucion_x, resolucion_y), titulo);
    player1 = new Player();
    
    //despues de construir la ventana, la dibuja
    gameLoop();
   
}



void Juego::dibujarPantalla(){

    this->ventanaJuego->clear();
    player1->dibujarPlayerPantalla( ventanaJuego );
    this->ventanaJuego->display();
}

void Juego::gameLoop(){
    sf::Event event;

    while( this->ventanaJuego->isOpen()){

        //condicion de salida(queu cierre la ventana)- IMPORTANTE
        while (this->ventanaJuego->pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                this->ventanaJuego->close();
        }
        //Mientras la ventana este abierta, va a dibujar(mostrar) la pantalla
        dibujarPantalla();

    }

}