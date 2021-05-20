#ifndef SPRITEA_H
#define SPRITEA_H

#include <SFML/Graphics.hpp>

#include <string>
#include <vector>
#include <iostream>


using std::string;
using std::vector;
using namespace sf;
using namespace std;
using std::cout;
using std::cin;
using std::endl;

class SpriteA{
    protected:
        
    public:

        //Atributos
        int cantFramesX;
        int cantFramesY;
        Texture* texturesPlayer;
        Sprite* spritesPlayer; //importante
        int spriteActual;
        Vector2i numFrame; //Frame actual del personaje
        Vector2f frameSize; // guardarael tamaño de cada frame
        FloatRect hitBox;



        //Funciones
        SpriteA();
        void setSprite(int claseSprite, int cantX, int cantY, Vector2i frameActual, Vector2f originPos = Vector2f(-100, -100));
        void selectFrame(); //carga el frame actual
        void setFrameX(int frame); //Modifica el frame de x actual a otro
        void setFrameY(int frame); //Modifica el frame de y actual a otro
        void animarFrame();
        Vector2f SpriteA::getFrameSize(){ return this->frameSize; }
};




#endif 