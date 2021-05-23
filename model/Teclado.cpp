#include "Teclado.h"

const int DERECHA = 1;
const int IZQUIERDA = 0; 
const int ARRIBA = 2;
const int ABAJO =3;

Teclado::Teclado(){
    evento = new Event;
}

Teclado* Teclado::getTeclado(){
    static Teclado t1;
    return &t1;
}


void Teclado::procesarEventos(){

    switch(evento->type)
    {
        case Event::Closed:
            exit(1);
            break;
        

        //PRESIONAR TECLA
        //
        //
        
        case Event::KeyPressed: //Procesamiento del teclado
            if(Keyboard::isKeyPressed(Keyboard::Left)){
            
                    teclasJugador[IZQUIERDA] = true; //habilito tecla izquierda
                    

            }
            else if(Keyboard::isKeyPressed(Keyboard::Right)){
                    
                    teclasJugador[DERECHA] = true;
                    

            }
            else if(Keyboard::isKeyPressed(Keyboard::Up)){

                    teclasJugador[ARRIBA] = true;

                    
                
            }
            else if(Keyboard::isKeyPressed(Keyboard::Down)){
 
                    teclasJugador[ABAJO] = true;

                    

                
                
            }
            break;

        //SOLTAR TECLAS
        //
        //

        case Event::KeyReleased: //Procesamiento de soltar tecla
            
            if( evento->key.code == Keyboard::Left){
                    teclasJugador[IZQUIERDA] = false; //desactivo tecla izquierda
                
            }
            else if(evento->key.code == Keyboard::Right){
 
                    teclasJugador[DERECHA] = false;
                    

            }
            else if(evento->key.code == Keyboard::Up){
    
                    teclasJugador[ARRIBA] = false;
                    

                
                
            }
            else if(evento->key.code == Keyboard::Down){

                    teclasJugador[ABAJO] = false;
                    
                
                
            }
            break;

    }

}