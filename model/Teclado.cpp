#include "Teclado.h"

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
            
                    teclasJugador[0] = true; //habilito tecla izquierda
                    //j1->setFrameY(1);

            }
            else if(Keyboard::isKeyPressed(Keyboard::Right)){
                    
                    teclasJugador[1] = true;
                    //j1->setFrameY(2);

            }
            else if(Keyboard::isKeyPressed(Keyboard::Up)){

                    teclasJugador[2] = true;

                    //j1->setFrameY(3);  
                
            }
            else if(Keyboard::isKeyPressed(Keyboard::Down)){
 
                    teclasJugador[3] = true;

                    //j1->setFrameY(0);

                
                
            }
            break;

        //SOLTAR TECLAS
        //
        //

        case Event::KeyReleased: //Procesamiento de soltar tecla
            
            if( evento->key.code == Keyboard::Left){
                    teclasJugador[0] = false; //desactivo tecla izquierda
                
            }
            else if(evento->key.code == Keyboard::Right){
 
                    teclasJugador[1] = false;
                    //j1->setFrameX(0); 

            }
            else if(evento->key.code == Keyboard::Up){
    
                    teclasJugador[2] = false;
                    //j1->setFrameX(0);

                
                
            }
            else if(evento->key.code == Keyboard::Down){

                    teclasJugador[3] = false;
                    //j1->setFrameX(0);
                
                
            }
            break;

    }

}