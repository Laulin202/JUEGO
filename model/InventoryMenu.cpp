#include "InventoryMenu.h"

InventoryMenu::InventoryMenu(View& window, Font& font){
    // Init background
    background.setSize(Vector2f((float)window.getCenter().x * 2, (float)window.getCenter().y * 2));
    background.setFillColor(Color(20,20,20,100));

    // Init inventory slots
    if(!containerItemsTex->loadFromFile("src/images/inventory/inventory10slots.png")){
        cout << "ERROR: COULDNT LOAD THE FILE";
    }
    containerItems.setSize(Vector2f(76, 184));
    containerItems.setPosition(Vector2f(window.getCenter().x - 50, window.getCenter().y - 150));
    containerItems.setTexture(containerItemsTex);
}

void InventoryMenu::addButton( string key, int numBoton, string text, float position, float xRect, float yRect ){
    
}

int InventoryMenu::update(){
    if(Keyboard::isKeyPressed(Keyboard::Space)){
        return 2;
    }
    return 3;
}

void InventoryMenu::render(RenderWindow* window){
    window->draw(background);
    window->draw(containerItems);
}