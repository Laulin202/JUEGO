#include "Button.h"

Button::Button(){
    
}

Button::Button(String id, RectangleShape rect, int numBoton){ 
    this->id = id; 
    this->rect = rect; 
    this->numBoton = numBoton;
    if(numBoton <= 8)
        cargarTextura();
    else if( numBoton >= 15)
        cargarTextura();
    
}

void Button::cargarTextura(){
    String path;
    path = "src/images/textureCombate/Button" + to_string(numBoton) + ".png" ;
    textureButton = new Texture();
    textureButton->loadFromFile(path);
    rect.setTexture(textureButton);
}

void Button::reiniciarTextura(){
    rect.setTexture(NULL);
    cout << "Entre" << endl;
}