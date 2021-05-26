#include "Combat.h"

const int JUGADOR = 20;
const int ENEMIGO = 30;

const int ESCAPO = 21;
const int NO_ESCAPO = 22;

const float POSX_CASILLA1 = 595;
const float POSY_CASILLA1 = 465;

Combat::Combat()
{
}

Combat::Combat(RenderWindow &ventana, Player &player, Enemy &enemy)
{
    this->turn = 0;
    this->ventana = &ventana;
    this->player = &player;
    this->enemy = &enemy;
}

void Combat::iniciarRectangulos() 
{
    cout << "Hola" << endl;
    for (int i = 0; i < 13; i++) 
    {

        String id = "";
        RectangleShape *r = new RectangleShape({140, 40});

        switch (i)
        {
        case 0:
            r->setPosition(48, 452);
            r->setSize(Vector2f(143, 40));
            id = "Atacar";

            break;

        case 1:
            r->setPosition(48, 500);
            r->setSize(Vector2f(143, 40));
            id = "Inventario";
            break;

        case 2:
            r->setPosition(48, 548);
            r->setSize(Vector2f(143, 40));
            id = "Escapar";
            break;

        case 3:
            r->setPosition(200, 548);

            id = "Menu";
            break;

        case 4:
            r->setPosition(200, 452);
            id = "Habilidad 1";
            break;
        case 5:
            r->setPosition(350, 452);
            id = "Habilidad 2";
            break;
        case 6:
            r->setPosition(200, 500);
            id = "Habilidad 3";
            break;
        case 7:
            r->setPosition(350, 500);
            id = "Habilidad 4";
            break;
        case 8:
            r->setPosition(585, 455);
            r->setSize(Vector2f( 150,130));
            id = " Cuadro Inventario";
            break;
        case 9:
            r->setPosition(POSX_CASILLA1, POSY_CASILLA1);
            r->setSize(Vector2f( 60, 50 ));
            r->setTexture(player->getPotion(0).getTexture());
            id = "Casilla 1";
            break;
        case 10:
            r->setPosition(POSX_CASILLA1 + 72, POSY_CASILLA1);
            r->setSize(Vector2f( 60, 50 ));
            r->setFillColor(Color::Transparent);
            id = "Casilla 2";
            break;
        case 11:
            r->setPosition( POSX_CASILLA1, POSY_CASILLA1 + 63 );
            r->setSize(Vector2f( 60, 50 ));
            r->setFillColor(Color::Transparent);
            id = "Casilla 3";
            break;
        case 12:
            r->setPosition( POSX_CASILLA1 + 72, POSY_CASILLA1 + 63 );
            r->setSize(Vector2f( 60, 50 ));
            r->setFillColor(Color::Transparent);
            id = "Casilla 4";
            break;
        default:
            break;
        }
        listaOpciones.push_back(Button(id, *r, i));
    }
}

void Combat::renderPanelOpciones()
{

    if (turnoJugador)
    {
        if (estadosBotones == estadosB::menu)
        {
            if (useSpell)
            {
                dibujarMensaje(JUGADOR);
                turnoJugador = false;
            }
            else if(usePotion){
                dibujarMensaje(JUGADOR);
                turnoJugador = false;
            }
            else{
                dibujarMenuPrincipal();
            }
        }
        else if (estadosBotones == estadosB::atacar)
        {
            dibujarMenuHabilidades();
        }
        else if (estadosBotones == estadosB::inventario)
        {
            dibujarInventario();
        }
        else if( estadosBotones == estadosB::escapar){
            if(!tryEscape()){
                dibujarMensaje(JUGADOR, NO_ESCAPO);
                turnoJugador = false;
                estadosBotones = menu;  
            }
            else{
                cout << "bye bye " << endl;
                dibujarMensaje(JUGADOR, ESCAPO);
                enCombate = false;
            }
        }
    }
    else{
        dibujarMensaje(ENEMIGO);
        turnoJugador = true;
    }
}

void Combat::renderizarCombate()
{

    ventana->clear();
    ventana->draw(*spriteCombate);
    renderPlayer();
    renderPanelOpciones();
    ventana->display();
}

void Combat::procesarEventosCombate()
{
    while (ventana->pollEvent(*evento1))
    {
        switch (evento1->type)
        {
        case Event::Closed:
            exit(1);
            break;

        case Event::MouseButtonReleased:
            if (evento1->mouseButton.button == Mouse::Left)
            {
                Vector2i posMouse;
                posMouse = Mouse::getPosition(*ventana);

                for (Button boton : listaOpciones)
                {

                    if (boton.getRect().getGlobalBounds().contains(posMouse.x, posMouse.y))
                    {

                        if (boton.getId() == "Atacar")
                        {
                            estadosBotones = estadosB::atacar;
                            cout << "Entre a atacar!" << endl;
                        }
                        if (boton.getId() == "Inventario")
                        {
                            estadosBotones = estadosB::inventario;
                            cout << "Entre a INVENTARIO!" << endl;
                        }
                        if (boton.getId() == "Escapar"){
                    
                            estadosBotones = estadosB::escapar;
                            cout << "Entre a ESCAPAR!" << endl;
                        }
                        if (boton.getId() == "Menu")
                        {
                            estadosBotones = estadosB::menu;
                            cout << "Volvi a menu!" << endl;
                        }
                        if (boton.getId() == "Habilidad 1")
                        {
                            estadosBotones = estadosB::menu;
                            cout << "Estoy usando habilidad 1!" << endl;
                            useSpell = true;
                            hechizoUsado = player->getSpell(0);
                            useAttackSpell(hechizoUsado);

                            
                        }
                        if (boton.getId() == "Habilidad 2")
                        {   
                          if( player->getMana() >= player->getSpell(1).getManaCost() ){
                            estadosBotones = estadosB::menu;
                            cout << "Estoy usando habilidad 2!" << endl;
                            useSpell = true;
                            hechizoUsado = player->getSpell(1);
                            useAttackSpell(hechizoUsado);
                            cout << "Sali" << endl;
                          }else
                          {
                            cout << "No me alcanza el mana UwU!" << endl;
                          }
                        }
                        if (boton.getId() == "Habilidad 3")
                        { 
                            if( player->getMana() >= player->getSpell(2).getManaCost() )
                            {
                              estadosBotones = estadosB::menu;
                              cout << "Estoy usando habilidad 3!" << endl;
                              useSpell = true;
                              hechizoUsado = player->getSpell(2);
                              
                              useAttackSpell(hechizoUsado);
                            }else
                            {
                              cout << "No me clanza el mana! :C" << endl;
                            }
                        }
                        if (boton.getId() == "Habilidad 4")
                        {
                            if( player->getMana() >= player->getSpell(3).getManaCost() )
                            {
                              estadosBotones = estadosB::menu;
                              cout << "Estoy usando habilidad 4!" << endl;
                              useSpell = true;
                              hechizoUsado = player->getSpell(3);
                              useAttackSpell(hechizoUsado);
                              cout << "Sali" << endl;
                            }else
                            {
                              cout << "Mana cost: " << player->getSpell(3).getManaCost() << endl;
                              cout << "Yummi no te quiere dar de su cum" << endl;
                            }
                        }
                        if (boton.getId() == "Casilla 1"){
                            String path;
                            path = "src/images/textureItems/Predefinido.png";
                            estadosBotones = estadosB::menu;
                            player->deleteItem(0);
                            player->getPotion(0).getTexture()->loadFromFile(path);
                            cout << "Usaste posion 1 " << endl;
                            usePotion = true;
                            
                            
                        }
                        
                    }
                }
            }
            break;

        default:
            break;
        }
    }
}

//Function tryEscape
//checks if is posible to escape
bool Combat::tryEscape()
{
    srand(time(NULL));
    int esc = rand() % 10;
    if (esc % 2 == 0)
    {
        return false; //true
    }
    return false; 
}

//Function useAttackSpell
//hechizoUsado is the spell to be used
//enemy is the enemy to be attacked
void Combat::useAttackSpell(Spell &hechizoUsado)
{
    int enemyHealth = this->enemy->getHealthPoints();
    int spellDamage = hechizoUsado.getDamage();
    enemyHealth = enemyHealth - spellDamage;
    cout << spellDamage << "!\n";
    this->enemy->setHealthPoints(enemyHealth);
    this->turn++;
    this->player->setMana( player->getMana() - hechizoUsado.getManaCost() );
    return;
}

//Function for 4th ability
//cum de Yummi attack
//Works with randoms (that's why is special)
void Combat::useSpecialAttackSpell(Spell &hechizoUsado)
{
    srand(time(NULL));
    int enemyHealth = this->enemy->getHealthPoints();
    int spellDamage = rand() % this->player->getAttackDamage() * 5;
    enemyHealth = enemyHealth - spellDamage;
    cout << spellDamage << "!\n";
    this->enemy->setHealthPoints(enemyHealth);
    this->turn++;
    return;
}

//Function attackPlayer
//attacks the player
void Combat::attackPlayer()
{
    srand(time(NULL));
    int enemyAttackDamage = this->enemy->getAttackDamage();
    int playerHealth = this->player->getHealthPoints();
    enemy->setDamageinCombat(rand() % enemyAttackDamage + (int)enemyAttackDamage + 2 / 2);
    this->player->setHealthPoints(playerHealth - enemy->getDamageinCombat());
    this->turn++;
    cout << "El enemigo te ataco, perdiste " << enemy->getDamageinCombat() << " de vida. " << endl;
    return;
}

//Function checkVictory
//Checks if the enemy is dead
bool Combat::checkVictory()
{
    if (this->enemy->getHealthPoints() <= 0)
    {
        return true;
    }
    return false;
}

//Function checkDefeat
//Checks if the players is dead
bool Combat::checkDefeat()
{
    if (this->player->getHealthPoints() <= 0)
    {
        return true;
    }
    return false;
}

void Combat::procesarLogicaCombate()
{
    procesarEventosCombate();
    //Here we attack the player on even turns
    if (turn % 2 != 0)
    {
        attackPlayer();
    }
    //If enemies health is 0 or less then is victory
    if (checkVictory())
    {
        cout << "Victoria\n";
        enCombate = false;
    }
    //If players health is 0 or less then is defeat
    else if (checkDefeat())
    {
        cout << "Derrota\n";
        enCombate = false;
    }
    //falta mas logica
}

void Combat::dibujarMenuPrincipal()
{
    int i = 0;
    for (list<Button>::iterator botonIt = listaOpciones.begin(); botonIt != listaOpciones.end(); botonIt++)
    {
        if (i < 3)
        {
            ventana->draw(botonIt->getRect());
        }
        i++;
    }
}

void Combat::dibujarInventario()
{
    int i = 0;
    for (list<Button>::iterator botonIt = listaOpciones.begin(); botonIt != listaOpciones.end(); botonIt++)
    {

        switch (i)
        {
        case 3:
            ventana->draw(botonIt->getRect());
            break;
        case 8:
            ventana->draw(botonIt->getRect());
            break;
        case 9:
            ventana->draw(botonIt->getRect());
            break;
        case 10:
            ventana->draw(botonIt->getRect());
            break;
        case 11:
            ventana->draw(botonIt->getRect());
            break;
        case 12:
            ventana->draw(botonIt->getRect());
            break;
        default:
            break;
        }
        i++;
    }
}

void Combat::dibujarMenuHabilidades()
{
    int i = 0;
    for (list<Button>::iterator botonIt = listaOpciones.begin(); botonIt != listaOpciones.end(); botonIt++)
    {
        switch (i)
        {
        case 3:
            ventana->draw(botonIt->getRect());
            break;
        case 4:
            ventana->draw(botonIt->getRect());
            break;
        case 5:
            ventana->draw(botonIt->getRect());
            break;
        case 6:
            ventana->draw(botonIt->getRect());
            break;
        case 7:
            ventana->draw(botonIt->getRect());
            break;

        default:
            break;
        }
        i++;
    }
}

void Combat::iniciarComponentesCombate()
{
    texturaBackground = new Texture();
    texturaBackground->loadFromFile("src/images/textureCombate/Captura.png");
    spriteCombate = new Sprite(*texturaBackground);
    iniciarRectangulos();
    evento1 = new Event();
    opcion = 1;

    //creamos los mensajes para el jugador
    fontMensaje = new Font();
    if(!fontMensaje->loadFromFile("src/fonts/arial.ttf")){
        cout << "Error al cargar la fuente!" << endl;
        exit(1);
    }
    mensaje.setFont(*fontMensaje);
    mensaje.setPosition(Vector2f(150, 500));
    mensaje.setCharacterSize(20);


    player->setPosSpriteCombate(Vector2f(110,180));
    player->setScaleSpriteCombate(Vector2f(2.5,2.5));

}

void Combat::dibujarMensaje(int personaje, int opcion)
{
    Clock *reloj;
    Time *cronometro;

    switch (opcion)
    {
    case NO_ESCAPO:
        mensaje.setString(" El enemigo te intimido, no lograste escapar ");
        this->turn++;
        break;
    case ESCAPO:
        mensaje.setString(" Escape exitoso.");
        break; 
    default:
        break;
    }

    mensaje.setFillColor(Color::Black);
    reloj = new Clock();
    cronometro = new Time();
    //Tiempo transcurrido
    while (reloj->getElapsedTime().asSeconds() < 3.f)
    { //Evaluar un cronometro de segundos
        ventana->draw(mensaje);
        ventana->display();
    }
}

void Combat::dibujarMensaje(int personaje){
    Clock *reloj;
    Time *cronometro;
    switch (personaje)
        {
        case JUGADOR:
            if(useSpell){
                mensaje.setString(" Haz usado  " + hechizoUsado.getName() + ", hiciste un dahno de: " + to_string(hechizoUsado.getDamage()) + " pts. ");
                useSpell = false;
            }
            else if(usePotion){
                mensaje.setString(" Haz usado una pocion ");
                this->turn++;
                usePotion = false;
            }
            break;
        case ENEMIGO:
            mensaje.setString(" El enemigo te ha hecho daño, perdiste " + to_string( enemy->getDamageinCombat() ) + " de vida.");
            break; 
        default:
            break;
        }

    mensaje.setFillColor(Color::Black);
    reloj = new Clock();
    cronometro = new Time();
    //Tiempo transcurrido
    while (reloj->getElapsedTime().asSeconds() < 3.f)
    { //Evaluar un cronometro de segundos
        ventana->draw(mensaje);
        ventana->display();
    }

}

void Combat::renderPlayer(){

    Clock* reloj;
    Time* tiempo;
    
    player->animarFrame(2);
    ventana->draw(player->getSpriteCombat());
}