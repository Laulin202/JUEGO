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

    //Atributos
        int cantFramesX;
        int cantFramesY;
        Texture* texturesPlayer;
        Sprite* spritesPlayer; //importante
        int spriteActual;
        Vector2i numFrame; //Frame actual del personaje
        Vector2f frameSize; // guardara el tamaño de cada frame
        FloatRect hitBox;
        RectangleShape* rectangle;


        //Apartado combate

        int cantFramesCombatX;
        int cantFramesCombatY;
        Texture* texturePlayerCombat;
        Sprite* spritePlayerCombat;
        Vector2i numFrameCombat;
        Vector2f frameSizeCombat;
        RectangleShape* rectangleCombat;

        
    public:

        


        //Funciones
        SpriteA();
        void setSprite(int claseSprite, int cantX, int cantY, Vector2i frameActual, Vector2f originPos = Vector2f(500, 500));
        void selectFrame(int opcion); //carga el frame actual
        void setFrameX(int frame); //Modifica el frame de x actual a otro
        void setFrameY(int frame); //Modifica el frame de y actual a otro
        void createHitBox(Vector2f originPos);
        void createRectangle(Vector2f originPos);
        void animarFrame(int opcion);
        Vector2f getFrameSize(){ return this->frameSize; }

        //Funciones
        void setSpriteCombate(int claseSprite, int cantX, int cantY, Vector2i frameActual, Vector2f scale = Vector2f(2.5,2.5));
        void setPosSpriteCombate( Vector2f pos ){ this->spritePlayerCombat->setPosition(pos); }
        void setScaleSpriteCombate( Vector2f scale){ this->spritePlayerCombat->setScale(scale); }
        Sprite getSpriteCombat(){ return *spritePlayerCombat; }
};




#endif 