#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "juego.h"

using std::cout;
using std::cin;
using std::string;


int main()
{

    Juego* pruebaJuego;
    pruebaJuego = new Juego(800, 600, "Programa de prueba");

    return 0;
}

