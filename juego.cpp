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
    initializeEnemiesNormal();
    initializeBasicItems();
    initializeArtifact();

    //Me permitira entrar a un Loop hasta que no termine el juego 
    gameLoop();
}


// mantiene la ventana mostrandose, procesando eventos y animando
void Juego::gameLoop(){
    
    while( gameState != gameOver ){

        *cronometro1 = reloj1->getElapsedTime(); //Tiempo transcurrido
        if(cronometro1->asSeconds() > 1 / fps){ //un frame cada 0,016 milisegundos
            
            if( !combatePlayer->isOver() ){
                if( gameState == unpaused ){ //unpaused update

                    procesarLogica();

                    ventana->setView(view);
                    
                    procesarNetworking();

                }else if( gameState == paused ){ //paused update
                    gameState = updateState(pMenu->update());
                }else if( gameState == inventory ){
                    gameState = updateState(iMenu->update());
                }
                renderizar();
                reloj1->restart();
            }else{ 
                combatePlayer->procesarLogicaCombate();
                combatePlayer->renderizarCombate();
                if( !combatePlayer->isOver() ){
                    if( combatePlayer->checkVictory() ){
                        if(enemies[enemieInCombat]->getProtector()){
                            puertasMap.erase(enemieInCombat);
                            map->updateBlockedTiles(enemieInCombat);
                        }
                        enemies.erase(enemieInCombat);
                        contEnemiesDefeated++;
                        if(contEnemiesDefeated == 9){
                            puertasMap.erase(5);
                            map->updateBlockedTiles(5);
                        } else if(contEnemiesDefeated == 18){
                            puertasMap.erase(7);
                            map->updateBlockedTiles(7);
                        }
                    }
                    j1->setPos(j1->getPreviousPosition());
                    j1->resetMovement();
                }
            }
        }
        if(j1->getHealthPoints() <= 0){
            gameState = updateState(0);
        }
    }
}

void Juego::procesarLogica(){
    j1->procesarEventos();
    updateBorderCollision();
    updateItemsCollision();
    if(updateTileCollision()){
        j1->checkCollisionDirection();
    }
    updateView();
    if(j1->walking){
        j1->animarFrame(1);
    }
    if(!enemies.empty()){
        std::map<int, Enemy*>::iterator itr;
        for(itr = enemies.begin(); itr != enemies.end(); ++itr){
            if(j1->getHitBox().intersects(itr->second->getHitBox())){
                j1->walking = false;
                combatePlayer = new Combat( *ventana, *j1, *itr->second );
                combatePlayer->iniciarComponentesCombate();
                combatePlayer->startCombat();
                view.setCenter( combatView );
                enemieInCombat = itr->first;
            }
        }
    }
    if(j1->getHitBox().intersects(artifact->getHitBox())){
        gameState = updateState(0);
    }
}

void Juego::procesarNetworking(){
    if(Keyboard::isKeyPressed(Keyboard::Escape)){
        pause();
    }
    /*else if(Keyboard::isKeyPressed(Keyboard::E)){ (No funciona)
        openInventory();
    }*/
}

void Juego::renderizar(){
    ventana->clear();
    ventana->draw(*map);
    if(!enemies.empty()){
        std::map<int, Enemy*>::iterator itr;
        for(itr = enemies.begin(); itr != enemies.end(); ++itr){
            if(gameState == unpaused){
                itr->second->animarFrame(1);
            }
            ventana->draw(itr->second->getSprite());
            //ventana->draw(itr->second->getRectangle());
        }
    }
    if(!mapItems.empty()){
        for(int i = 0; i < mapItems.size(); i++){
            ventana->draw(*mapItems[i]->getSprite());
        }
    }
    ventana->draw(*artifact->getSprite());
    ventana->draw(j1->getSprite());
    //ventana->draw(j1->getRectangle());
    if(gameState == paused){
        pMenu->render( ventana );
    }else if(gameState == inventory){
        iMenu->render( ventana );
    }
    ventana->display();
}

void Juego::pause(){
    gameState = paused;
    pMenu = new PauseMenu( view, font );
}

void Juego::openInventory(){
    gameState = inventory;
    iMenu = new InventoryMenu( view, font );
}

game_states Juego::updateState( int state ){
    if(state == 2){
        return unpaused;
    }else if(state == 0){
        return gameOver;
    }else if(state == 3){
        return inventory;
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
    multimap<int, FloatRect>::iterator position;
    for(position = puertasMap.begin(); position != puertasMap.end(); ++position){
        if(j1->getHitBox().intersects(position->second)){
            collision = true;
        }
    }
    return collision;
}

void Juego::updateItemsCollision(){
    if(!mapItems.empty()){
        for(int i = 0; i < mapItems.size(); i++){
            if(j1->getHitBox().intersects(mapItems[i]->getHitBox())){
                j1->addItem(mapItems[i]);
                mapItems.erase(mapItems.begin() + i);
            }
        }
    }
}

void Juego::updateView(){
    view.setCenter(j1->getPos());
}

void Juego::iniciar(){
    loadMap();
    j1 = new Player(*ventana,12, 4, 4, Vector2i(2,1), Vector2f(792, 2280));
    fps = 2; // 60 Frames x Seconds
    reloj1 = new Clock();
    //reloj2 = new Clock();
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
    map = new TileMap(tileset, 122, 100, 24.0f, 24.0f); 
    mapBox = map->getArray()->getBounds();
    tilesArray = map->getTilesArray();
    puertasMap = map->getBloqueosHitbox();
}

void Juego::iniciarView(){
    view.setSize( Vector2f( ventana->getSize().x, ventana->getSize().y ) );
    view.setCenter( Vector2f( ventana->getSize().x/2.f, ventana->getSize().y/2.f ) );
    combatView = Vector2f( ventana->getSize().x/2.f, ventana->getSize().y/2.f );
}

void Juego::initializeEnemiesNormal(){
    e1 = new Enemy("Damian", 30, 10, 470, 8, 1, Vector2i(0,0), Vector2f(1104, 1848), "Tetokoahi", "Tencuero tres mil", Vector2f(2.5, 2.5), true);
    enemies.insert(pair <int, Enemy*> (1, e1));
    e1 = new Enemy("Demon Hunter", 30, 12, 490, 4, 1, Vector2i(0,0), Vector2f(470, 1848), "Justice Spear", "Gorogorogoro", Vector2f(2.5, 2.5), true);
    enemies.insert(pair <int, Enemy*> (2, e1));
    e1 = new Enemy("Lava Demon", 35, 10, 500, 6, 1, Vector2i(0,0), Vector2f(1130, 1464), "Thyplosion", "Lava spiral", Vector2f(3, 3), true);
    enemies.insert(pair <int, Enemy*> (3, e1));
    e1 = new Enemy("XDeath", 50, 10, 520, 4, 1, Vector2i(0,0), Vector2f(466, 1440), "Surrounding death", "Rise from the grave", Vector2f(2.5, 2.5), true);
    enemies.insert(pair <int, Enemy*> (4, e1));
    e1 = new Enemy("Turret mommy", 30, 10, 540, 8, 1, Vector2i(0,0), Vector2f(780, 1280), "Sandstorm", "Killer sand", Vector2f(2.5, 2.5));
    enemies.insert(pair <int, Enemy*> (5, e1));
    e1 = new Enemy("Jaiba", 24, 10, 560, 5, 1, Vector2i(0,0), Vector2f(1416, 1848), "Krusty Krab", "Jaiba attack", Vector2f(2.5, 2.5));
    enemies.insert(pair <int, Enemy*> (6, e1));
    e1 = new Enemy("Himalaya", 40, 6, 580, 8, 1, Vector2i(0,0), Vector2f(1440, 1464), "GRRRRR", "Peace was never an option", Vector2f(2.5, 2.5));
    enemies.insert(pair <int, Enemy*> (7, e1));
    e1 = new Enemy("Alien", 15, 15, 600, 9, 1, Vector2i(0,0), Vector2f(144, 1848), "Brainwash", "Braindead", Vector2f(2.5, 2.5));
    enemies.insert(pair <int, Enemy*> (23, e1));
    e1 = new Enemy("Senran Kagura", 35, 10, 620, 8, 1, Vector2i(0,0), Vector2f(144, 1464), "X-cut", "Haruka Kanata", Vector2f(2.5, 2.5));
    enemies.insert(pair <int, Enemy*> (9, e1));
    e1 = new Enemy("Jaiba", 24, 10, 560, 5, 1, Vector2i(0,0), Vector2f(1032, 1368), "Krusty Krab", "Jaiba attack", Vector2f(2.5, 2.5));
    enemies.insert(pair <int, Enemy*> (10, e1));
    e1 = new Enemy("Alien", 15, 15, 600, 9, 1, Vector2i(0,0), Vector2f(912, 1944), "Brainwash", "Braindead", Vector2f(2.5, 2.5));
    enemies.insert(pair <int, Enemy*> (11, e1));
    e1 = new Enemy("Alien", 15, 15, 640, 11, 1, Vector2i(0,0), Vector2f(552, 1656), "Brainwash", "Braindead", Vector2f(2.5, 2.5));
    enemies.insert(pair <int, Enemy*> (12, e1));
    e1 = new Enemy("Himalaya", 40, 6, 580, 8, 1, Vector2i(0,0), Vector2f(1056, 1032), "GRRRRR", "Peace was never an option", Vector2f(2.5, 2.5));
    enemies.insert(pair <int, Enemy*> (13, e1));
    e1 = new Enemy("Himalaya", 40, 6, 580, 8, 1, Vector2i(0,0), Vector2f(1056, 840), "GRRRRR", "Peace was never an option", Vector2f(2.5, 2.5));
    enemies.insert(pair <int, Enemy*> (14, e1));
    e1 = new Enemy("PHAN PHAN", 60, 10, 660, 4, 1, Vector2i(0,0), Vector2f(1440, 960), "STAMPEDE!", "Water beam", Vector2f(2.5, 2.5));
    enemies.insert(pair <int, Enemy*> (15, e1));
    e1 = new Enemy("Senran Kagura", 35, 15, 620, 8, 1, Vector2i(0,0), Vector2f(1920, 620), "X-cut", "Haruka Kanata", Vector2f(2.5, 2.5));
    enemies.insert(pair <int, Enemy*> (16, e1));
    e1 = new Enemy("Senran Kagura", 35, 15, 620, 8, 1, Vector2i(0,0), Vector2f(2040, 620), "X-cut", "Haruka Kanata", Vector2f(2.5, 2.5));
    enemies.insert(pair <int, Enemy*> (17, e1));
    e1 = new Enemy("Lava Demon", 40, 10, 500, 6, 1, Vector2i(0,0), Vector2f(1896, 1056), "Thyplosion", "Lava spiral", Vector2f(2.5, 2.5));
    enemies.insert(pair <int, Enemy*> (18, e1));
    e1 = new Enemy("Jaiba", 24, 10, 560, 5, 1, Vector2i(0,0), Vector2f(2136, 816), "Krusty Krab", "Jaiba attack", Vector2f(2.5, 2.5));
    enemies.insert(pair <int, Enemy*> (19, e1));
    e1 = new Enemy("Jaiba", 24, 10, 560, 5, 1, Vector2i(0,0), Vector2f(2112, 1056), "Krusty Krab", "Jaiba attack", Vector2f(2.5, 2.5));
    enemies.insert(pair <int, Enemy*> (20, e1));
    e1 = new Enemy("Lanzerto", 15, 20, 680, 6, 1, Vector2i(0,0), Vector2f(648, 960), "Immortal Shieldbow", "Stattik", Vector2f(2.5, 2.5));
    enemies.insert(pair <int, Enemy*> (21, e1));
    e1 = new Enemy("Death Dance", 60, 20, 700, 2, 1, Vector2i(0,0), Vector2f(2448, 960), "Electric Bubbalu", "Let it rip", Vector2f(2.5, 2.5));
    enemies.insert(pair <int, Enemy*> (22, e1));
    e1 = new Enemy("NIGHTMARE", 100, 25, 720, 5, 1, Vector2i(0,0), Vector2f(1968, 120), "MIRROR WORLD", "Break it", Vector2f(2.5, 2.5), true);
    enemies.insert(pair <int, Enemy*> (8, e1));
    e1 = new Enemy("Himalaya", 40, 6, 580, 8, 1, Vector2i(0,0), Vector2f(888, 1680), "GRRRRR", "Peace was never an option", Vector2f(2.5, 2.5));
    enemies.insert(pair <int, Enemy*> (24, e1));
    e1 = new Enemy("Alien", 15, 15, 640, 11, 1, Vector2i(0,0), Vector2f(1824, 744), "Brainwash", "Braindead", Vector2f(2.5, 2.5));
    enemies.insert(pair <int, Enemy*> (25, e1));

}
// FUNCIONES FASE PRUEBA, FALTA PASARLOS A UNA CLASE COMBATE Y AJUSTARLOS AHI

void Juego::initializeBasicItems(){
    srand(time(NULL));
    int pos;
    itemsPositions.push_back(Vector2f(48, 1824));
    itemsPositions.push_back(Vector2f(48, 1464));
    itemsPositions.push_back(Vector2f(1512, 1848));
    itemsPositions.push_back(Vector2f(1512, 1464));
    itemsPositions.push_back(Vector2f(480, 1992));
    itemsPositions.push_back(Vector2f(840, 2328));
    itemsPositions.push_back(Vector2f(624, 1488));
    itemsPositions.push_back(Vector2f(768, 1632));
    itemsPositions.push_back(Vector2f(816, 864));
    itemsPositions.push_back(Vector2f(912, 1032));
    itemsPositions.push_back(Vector2f(912, 840));
    itemsPositions.push_back(Vector2f(1968, 1008));
    itemsPositions.push_back(Vector2f(2088, 1056));
    itemsPositions.push_back(Vector2f(2136, 648));
    itemsPositions.push_back(Vector2f(2424, 1080));
    itemsPositions.push_back(Vector2f(864, 1512));
    itemsPositions.push_back(Vector2f(624, 1968));
    itemsPositions.push_back(Vector2f(1656, 936));
    itemsPositions.push_back(Vector2f(1320, 1368));
    itemsPositions.push_back(Vector2f(1224, 936));
    itemsPositions.push_back(Vector2f(864, 2184));
    itemsPositions.push_back(Vector2f(576, 1344));

    pos = randomItemPos();
    item1 = new Weapon("Arma comun", "Vieja arma dejada atras por los ahora convertidos en criaturas de otra realidad", 1+rand()%15, 5, itemsPositions[pos]);
    itemsPositions.erase(itemsPositions.begin() + pos);
    mapItems.push_back(item1);

    srand(time(NULL));
    pos = randomItemPos();
    item1 = new Weapon("Arma comun", "Vieja arma dejada atras por los ahora convertidos en criaturas de otra realidad", 1+rand()%15, 5, itemsPositions[pos]);
    itemsPositions.erase(itemsPositions.begin() + pos);
    mapItems.push_back(item1);

    srand(time(NULL));
    pos = randomItemPos();
    item1 = new Weapon("Arma comun", "Vieja arma dejada atras por los ahora convertidos en criaturas de otra realidad", 1+rand()%15, 5, itemsPositions[pos]);
    itemsPositions.erase(itemsPositions.begin() + pos);
    mapItems.push_back(item1);

    srand(time(NULL));
    pos = randomItemPos();
    item1 = new Weapon("Arma comun", "Vieja arma dejada atras por los ahora convertidos en criaturas de otra realidad", 1+rand()%15, 5, itemsPositions[pos]);
    itemsPositions.erase(itemsPositions.begin() + pos);
    mapItems.push_back(item1);

    srand(time(NULL));
    pos = randomItemPos();
    item1 = new Weapon("Arma poco comun", "Otorgadas por el rey en persona para su proteccion y la de su familia", 20+rand()%11, 5, itemsPositions[pos]);
    itemsPositions.erase(itemsPositions.begin() + pos);
    mapItems.push_back(item1);

    srand(time(NULL));
    pos = randomItemPos();
    item1 = new Weapon("Arma poco comun", "Otorgadas por el rey en persona para su proteccion y la de su familia", 20+rand()%11, 5, itemsPositions[pos]);
    itemsPositions.erase(itemsPositions.begin() + pos);
    mapItems.push_back(item1);

    srand(time(NULL));
    pos = randomItemPos();
    item1 = new Weapon("Arma poco comun", "Otorgadas por el rey en persona para su proteccion y la de su familia", 20+rand()%11, 5, itemsPositions[pos]);
    itemsPositions.erase(itemsPositions.begin() + pos);
    mapItems.push_back(item1);

    srand(time(NULL));
    pos = randomItemPos();
    item1 = new Weapon("Arma poco comun", "Otorgadas por el rey en persona para su proteccion y la de su familia", 20+rand()%11, 5, itemsPositions[pos]);
    itemsPositions.erase(itemsPositions.begin() + pos);
    mapItems.push_back(item1);

    srand(time(NULL));
    pos = randomItemPos();
    item1 = new Weapon("Arma rara", "Armas forgadas con base en acero de damasco para la mayor resistencia y corte", 39+rand()%6, 5, itemsPositions[pos]);
    itemsPositions.erase(itemsPositions.begin() + pos);
    mapItems.push_back(item1);

    srand(time(NULL));
    pos = randomItemPos();
    item1 = new Weapon("Arma rara", "Armas forgadas con base en acero de damasco para la mayor resistencia y corte", 39+rand()%6, 5, itemsPositions[pos]);
    itemsPositions.erase(itemsPositions.begin() + pos);
    mapItems.push_back(item1);

    srand(time(NULL));
    pos = randomItemPos();
    item1 = new Weapon("Arma rara", "Armas forgadas con base en acero de damasco para la mayor resistencia y corte", 39+rand()%6, 5, itemsPositions[pos]);
    itemsPositions.erase(itemsPositions.begin() + pos);
    mapItems.push_back(item1);

    srand(time(NULL));
    pos = randomItemPos();
    item1 = new Weapon("Hacha del Verdugo", "Utilizadas para la decapitacion de aquellos que iban en contra de la ley divina del reino de Cyradil", 33+rand()%5, 5, itemsPositions[pos]);
    itemsPositions.erase(itemsPositions.begin() + pos);
    mapItems.push_back(item1);

    srand(time(NULL));
    pos = randomItemPos();
    item1 = new Chestplate("Pechera del rey", "Vieja pechera utilizada por el rey Jarvan III en la guerra de los Mil Dias", 3, 5, itemsPositions[pos]);
    itemsPositions.erase(itemsPositions.begin() + pos);
    mapItems.push_back(item1);

    srand(time(NULL));
    pos = randomItemPos();
    item1 = new Chestplate("Pechera Ornstein", "Una de las pecheras mas resistentes del mundo, la cual ha resistido millones de batallas", 5, 5, itemsPositions[pos]);
    itemsPositions.erase(itemsPositions.begin() + pos);
    mapItems.push_back(item1);

    srand(time(NULL));
    pos = randomItemPos();
    item1 = new Helmet("Casco de toro", "Los cuernos en verdad no son de toro, nadie sabe de que son pero si se sabe que han atravesado a miles de enemigos", 1, 5, itemsPositions[pos]);
    itemsPositions.erase(itemsPositions.begin() + pos);
    mapItems.push_back(item1);

    srand(time(NULL));
    pos = randomItemPos();
    item1 = new Helmet("Corona de la reina", "Utilizada por la reina Isabel", 3, 5, itemsPositions[pos]);
    itemsPositions.erase(itemsPositions.begin() + pos);
    mapItems.push_back(item1);

    srand(time(NULL));
    pos = randomItemPos();
    item1 = new Leggings("Perneras de lava", "Perneras construidas con el fin de atravesar las zonas mas calientes del submundo", 3, 5, itemsPositions[pos]);
    itemsPositions.erase(itemsPositions.begin() + pos);
    mapItems.push_back(item1);

    srand(time(NULL));
    pos = randomItemPos();
    item1 = new Potion("Agua Bendecida", "Otorga puntos de vida a todo aquel que la ingiera", 1, 50, restoreHealthPointsE, 3, itemsPositions[pos]);
    itemsPositions.erase(itemsPositions.begin() + pos);
    mapItems.push_back(item1);

    srand(time(NULL));
    pos = randomItemPos();
    item1 = new Potion("Berserk", "Otorga puntos de ataque a todo aquel que la ingiera", 2, 80, increaseAttackPointsE, 2, itemsPositions[pos]);
    itemsPositions.erase(itemsPositions.begin() + pos);
    mapItems.push_back(item1);

    srand(time(NULL));
    pos = randomItemPos();
    item1 = new Potion("Nigromancia", "Otorga puntos de vida y ataque a costa de tu moralidad", 3, 200, restoreHealthPointsE, 3, itemsPositions[pos]);
    itemsPositions.erase(itemsPositions.begin() + pos);
    mapItems.push_back(item1);

    srand(time(NULL));
    pos = randomItemPos();
    item1 = new Potion("Masoquismo", "Reduce tu salud al mínimo a la vez que te otorga puntos de ataque", 4, 50, increaseAttackPointsE, 3, itemsPositions[pos]);
    itemsPositions.erase(itemsPositions.begin() + pos);
    mapItems.push_back(item1);


}

void Juego::initializeArtifact(){
    artifact = new Weapon("Bendición de los caídos", "௯ ௮ ி ஞ ஜ ಋ   ಱ ಯ ಮ ಭ ಬ", 19, 100, Vector2f(768, 504));
}

int Juego::randomItemPos(){
    srand(time(NULL));
    return rand()%(itemsPositions.size() - 1);
}
