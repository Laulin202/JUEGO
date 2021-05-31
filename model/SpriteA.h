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

        int cantFramesX; // la cantidad de frames en x que tiene el sprite
        int cantFramesY; // la cantidad de frames en y que tiene el sprite
        Texture* texturesPlayer;
        Sprite* spritesPlayer; 
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

        SpriteA();

        // Setters
        void setSprite(int claseSprite, int cantX, int cantY, Vector2i frameActual, Vector2f originPos = Vector2f(500, 500)); // hace el cargue y ajuste del sprite normal de la entidad
        void setFrameX(int frame); //Modifica el frame de x actual a otro
        void setFrameY(int frame); //Modifica el frame de y actual a otro
        void setSpriteCombate(int claseSprite, int cantX, int cantY, Vector2i frameActual, Vector2f scale = Vector2f(2.5,2.5)); // Hace el cargue y ajuste del sprite de combate de la entidad
        void setPosSpriteCombate( Vector2f pos ){ this->spritePlayerCombat->setPosition(pos); } //Modifica la posisicon del sprite de combate
        void setScaleSpriteCombate( Vector2f scale){ this->spritePlayerCombat->setScale(scale); } //Modifica la escala del sprite dle combate


        //Getters
        Vector2f getFrameSize(){ return this->frameSize; } // retorna el tamaño de cada frame
        Sprite getSpriteCombat(){ return *spritePlayerCombat; } // retorna el sprite de combate de la entidad
        

        /*
        Nombre: selectFrame
        Output: N/A
        Input: opcion( si es del combate o el mapa normal)
        Funcion: Me permite cambiar el rectagulo para que agarre el frame correspondiente
        */
        void selectFrame(int opcion);

        /*
        Nombre: createHitBox
        Output: N/A
        Input: Vector2f
        Funcion: crea la hitbox teniendo en cuenta la posicicon del jugador
        */
        void createHitBox(Vector2f originPos);

        /*
        Nombre: createRectangle
        Output: N/A
        Input: Vector2f
        Funcion: crea el borde de la hitbox del pj 
        */
        void createRectangle(Vector2f originPos);

        /*
        Nombre: animarFrame
        Output: N/A
        Input: opcion (si esta en combate o normal)
        Funcion: anima los frames corrspondientes
        */
        void animarFrame(int opcion);
        
};




#endif 