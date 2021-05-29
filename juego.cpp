#include "juego.h"

/*
TODO: Acomodar en el Repositorio Juego:
Crear Combate.cpp
Mover por completo todo lo que tienes en Combat.cpp
Ajustar Combat.h
Ajustar la condicion isOver() (no olvides el !)


*/


const int ATTACK_DISTANCE = 15;

Juego::Juego(Vector2u resolucion){
    ventana = new RenderWindow(VideoMode(resolucion.x, resolucion.y), "Videojuego Prueba  2D");
    iniciar();
    iniciarView();
    initializeEnemies();

    //Me permitira entrar a un Loop hasta que no termine el juego 
    gameLoop();
}


// mantiene la ventana mostrandose, procesando eventos y animando
void Juego::gameLoop(){

    while( gameState != gameOver ){

        *cronometro1 = reloj1->getElapsedTime(); //Tiempo transcurrido
        if(cronometro1->asSeconds() > 1 / fps){ //un frame cada 0,016 milisegundos
            
            if( !combatePlayer->isOver() ){
                if( gameState != paused ){ //unpaused update

                    procesarLogica();

                    ventana->setView(view);
                    
                    procesarNetworking();
                
                }else{ //paused update
                    gameState = updateState(pMenu->update());
                    cout << Mouse::getPosition().x << " . " << Mouse::getPosition().y << endl;
                }
                renderizar();
                reloj1->restart();
            }else{ 
                combatePlayer->procesarLogicaCombate();
                combatePlayer->renderizarCombate();
                if( !combatePlayer->isOver() ){
                    enemies.erase(enemies.begin() + enemieInCombat);
                }
            }
        }
    }
}

void Juego::procesarLogica(){
    j1->procesarEventos();
    updateBorderCollision();
    if(updateTileCollision()){
        j1->checkCollisionDirection();
    }
    updateView();
    if(j1->walking){
        j1->animarFrame(1);
    }
    if(!enemies.empty()){
        for(int i = 0; i < enemies.size(); i++){
            enemies[i].animarFrame(1);
            if(j1->getHitBox().intersects(enemies[i].getHitBox())){
                combatePlayer = new Combat( *ventana, *j1, enemies[i] );
                combatePlayer->iniciarComponentesCombate();
                combatePlayer->startCombat();
                view.setCenter( combatView );
                enemieInCombat = i;
            }
        }
    }
}

void Juego::procesarNetworking(){
    if(Keyboard::isKeyPressed(Keyboard::Escape)){
        pause();
    }
}

void Juego::renderizar(){
    ventana->clear();
    ventana->draw(*map);
    if(!enemies.empty()){
        for(int i = 0; i < enemies.size(); i++){
            ventana->draw(enemies[i].getSprite());
            ventana->draw(enemies[i].getRectangle());
        }
    }
    ventana->draw(j1->getSprite());
    ventana->draw(j1->getRectangle());
    if(gameState == paused){
        pMenu->render( ventana );
    }
    ventana->display();
}

void Juego::pause(){
    gameState = paused;
    pMenu = new PauseMenu( view, font );
}

game_states Juego::updateState( int state ){
    if(state == 2){
        return unpaused;
    }else if(state == 0){
        return gameOver;
    }
    return paused;
}

void Juego::updateBorderCollision(){
    // Left Collision
    if(j1->getHitBox().left < mapBox.left){
        j1->setCLeft(true);
    }
    // Right Collision 
    else if(j1->getHitBox().left + j1->getHitBox().width >= mapBox.width){
        j1->setCRight(true);
    }
    // Top Collision
    if(j1->getHitBox().top < mapBox.top){
        j1->setCTop(true);
    } 
    // Bottom Collision
    else if(j1->getHitBox().top + j1->getHitBox().height >= mapBox.height){
        j1->setCBot(true);
    }
}

bool Juego::updateTileCollision(){
    bool collision = false;
    for(int i = 0; i < tilesArray.size(); i++){
        if(j1->getHitBox().intersects(tilesArray[i])){
            collision = true;
        }
    }
    return collision;
}

void Juego::updateView(){
    view.setCenter(j1->getPos());
}

void Juego::iniciar(){
    loadMap();
    j1 = new Player(*ventana,12, 4, 4, Vector2i(2,1), Vector2f(mapBox.width / 2, mapBox.height / 2));
    fps = 2; // 60 Frames x Seconds
    reloj1 = new Clock();
    cronometro1 = new Time();
    combatePlayer = new Combat();
    if(!font.loadFromFile("src/fonts/arial.ttf")){
        cout << "No se pudo cargar la fuente \n";
    }
    //Fase prueba
}

void Juego::loadMap(){ // se carga el mapa
    tileset = new Texture();
    tileset->loadFromFile("src/images/tileset/tileset.png");
    map = new TileMap(tileset, 122, 78, 24.0f, 24.0f); 
    mapBox = map->getArray()->getBounds();
    tilesArray = map->getTilesArray();
}

void Juego::iniciarView(){
    view.setSize( Vector2f( ventana->getSize().x, ventana->getSize().y ) );
    view.setCenter( Vector2f( ventana->getSize().x/2.f, ventana->getSize().y/2.f ) );
    combatView = Vector2f( ventana->getSize().x/2.f, ventana->getSize().y/2.f );
}

void Juego::initializeEnemies(){
    Enemy e1(470, 8, 1, Vector2i(0,0), Vector2f(300, 300), "Tetokoahi", "Tencuero tres mil");
    enemies.push_back(e1);
}
// FUNCIONES FASE PRUEBA, FALTA PASARLOS A UNA CLASE COMBATE Y AJUSTARLOS AHI





