#include "SpriteA.h"

SpriteA::SpriteA(){

}

//esta funcion me permite, cargar el sprite y guardarlo, ademas de hacer la correspondente particion de frames
void SpriteA::setSprite(int claseSprite, int cantX, int cantY, Vector2i frameActual, Vector2f originPos){

    cantFramesX = cantX; //cantidad casilleros en x
    cantFramesY = cantY; //cantidad casilleros en y
    
    //Basicamente es la ruta para buscar la imagen
    String path = "src/images/entities/" + to_string(claseSprite) + ".png";

    spriteActual = claseSprite;  //basicamente actualizo el num de png (sprite)
    texturesPlayer = new Texture();
    texturesPlayer->loadFromFile(path);
    spritesPlayer = new Sprite(*texturesPlayer); //cargo en su atributo el nuevo sprite a partir de dicha textura cargada

    frameSize = Vector2f(texturesPlayer->getSize().x/ cantX,texturesPlayer->getSize().y / cantY ); //obtengo la dimension o tamaño de cada frame o casilla del personaje en png
    numFrame = frameActual; //Frame actual de la imagen de todos los movimientos
    selectFrame();
    spritesPlayer->setOrigin(originPos);
    hitBox = spritesPlayer->getGlobalBounds();
}

//Me permite cambiar el rectagulo para que agarre el frame
void SpriteA::selectFrame(){
    IntRect rectangle( numFrame.x * frameSize.x, numFrame.y * frameSize.y, frameSize.x, frameSize.y); //recordemos que frameSize es un vector de 2 float
    spritesPlayer->setTextureRect(rectangle);
}

void SpriteA::animarFrame(){

    if(numFrame.x != cantFramesX - 1){ //Si aun no alcance el ultimo frame
        numFrame.x = numFrame.x+1; //incremento el frame
    }
    else{
        numFrame.x = 0; //reseteo el frame
    }
    
    selectFrame(); // selecciono el rectangulo correspondiente al frame con respecto al frame actual 

}

void SpriteA::setFrameX(int frame){
    numFrame.x = frame;
    selectFrame();

}

void SpriteA::setFrameY(int frame){
    numFrame.y = frame;
    selectFrame();
    
}