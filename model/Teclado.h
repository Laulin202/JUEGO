#ifndef TECLADO_H
#define TECLADO_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Teclado{

    private:
        Teclado();
        
    public:
        //Atributo publico, pendiente optimizar
        bool teclasJugador[4]; //sera una arreglo de booleanos de arriba, abajo, izquierda, derecha(para saber si lo esta presionando)
        Event* evento;


        void procesarEventos();
        static Teclado* getTeclado(); 
        





};


#endif