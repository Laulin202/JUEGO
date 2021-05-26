#include "PauseMenu.h"

PauseMenu::PauseMenu(View& window, Font& font){
    // Init background
    background.setSize(Vector2f((float)window.getCenter().x * 2, (float)window.getCenter().y * 2));
    background.setFillColor(Color(20,20,20,100));
    
    // Init container
    container.setSize(Vector2f(((float)window.getCenter().x * 2) / 4.f, (float)window.getCenter().y * 2));
    container.setFillColor(Color(20,20,20,200));
    container.setPosition(((float)window.getCenter().x * 2) / 2.f - container.getSize().x / 2.f, 0.f);

    // Init text
    menuText.setFont(font);
    menuText.setFillColor(Color(255, 255, 255, 200));
    menuText.setCharacterSize(32);
    menuText.setString("PAUSED");
    menuText.setPosition( container.getPosition().x + container.getSize().x / 2.f - menuText.getGlobalBounds().width / 2.f, (container.getSize().y / 3) - 30.f );

    // Init buttons
    resumeText.setFont(font);
    resumeText.setFillColor(Color(255, 255, 255, 200));
    resumeText.setCharacterSize(18);
    resumeText.setString("[SPACE] to");
    resumeText.setPosition( (container.getPosition().x + container.getSize().x / 2.f - menuText.getGlobalBounds().width / 2.f) + 10.f, (container.getSize().y / 2) - 31 * 3 );
    addButton( "RESUME", 16, "RESUME", 20, 90, 30);
    quitText.setFont(font);
    quitText.setFillColor(Color(255, 255, 255, 200));
    quitText.setCharacterSize(18);
    quitText.setString("[X] to");
    quitText.setPosition( (container.getPosition().x + container.getSize().x / 2.f - menuText.getGlobalBounds().width / 2.f ) + 10.f, (container.getSize().y / 2) + 8 * 3 );
    addButton( "QUIT", 15, "QUIT", -20, 80, 30);
}

void PauseMenu::addButton( string key, int numBoton, string text, float position, float xRect, float yRect ){
    RectangleShape button;
    button.setSize( Vector2f( xRect, yRect ) );
    float x = container.getPosition().x + container.getSize().x / 2.f - button.getSize().y - 20;
    float y = (container.getSize().y / 2) - position * 3;
    button.setPosition( Vector2f( x, y ) );
    buttons[key] = new Button( text, button, numBoton );
}

int PauseMenu::update(){
    if(Keyboard::isKeyPressed(Keyboard::Space)){
        return 2;
    }
    if(Keyboard::isKeyPressed(Keyboard::X)){
        return 0;
    }
    return 1;
}

void PauseMenu::render(RenderWindow* window){
    window->draw(background);
    window->draw(container);
    for(auto &i : buttons){
        window->draw(i.second->getRect());
    }
    window->draw(menuText);
    window->draw(resumeText);
    window->draw(quitText);
}