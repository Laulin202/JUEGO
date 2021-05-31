#ifndef TECLADO_H
#define TECLADO_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Teclado{

    private:
        Teclado();
        
    public:
        bool teclasJugador[4]; //sera una arreglo de booleanos de arriba, abajo, izquierda, derecha(para saber si lo esta presionando)
        Event* evento;

        /*
        Nombre: procesarEventos
        Output: N/A
        Input: N/A
        Funcion: revisa que tecla se esta precionando para actualizar su valor a True o False
        */
        void procesarEventos();

        /*
        Nombre: getTeclado
        Output: N/A
        Input: varieble tipo Teclado
        Funcion: crea un objeto de tipo Teclado y posterirmente retorna su apuntador
        */
        static Teclado* getTeclado();

        /*
        Nombre: updateKeys
        Output: N/A
        Input: N/A
        Funcion: Pasa todos los valores del vector de teclas a FALSE
        */
        void updateKeys(); 
        
};


#endif