#include "PauseMenu.h"

PauseMenu::PauseMenu(){}

PauseMenu::PauseMenu(RenderWindow& window){
    // Init background
    background.setSize(Vector2f((float)window.getSize().x, (float)window.getSize().y));
    background.setFillColor(Color(20,20,20,100));
    
    // Init container
    container.setSize(Vector2f((float)window.getSize().x / 4.f, (float)window.getSize().y));
    container.setFillColor(Color(20,20,20,200));
    container.setPosition((float)window.getSize().x / 2.f - container.getSize().x / 2.f, 0.f);
}

void PauseMenu::update(){

}

void PauseMenu::render(RenderTarget& window){
    window.draw(background);
    window.draw(container);
    for(auto &i : buttons){
        window.draw(i.second->getRect());
    }
}