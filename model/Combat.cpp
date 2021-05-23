#include "Combat.h"

const int JUGADOR = 20;
const int ENEMIGO = 30;

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
    for (int i = 0; i < 8; i++)
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
            }
            dibujarMenuPrincipal();
        }
        else if (estadosBotones == estadosB::atacar)
        {
            dibujarMenuHabilidades();
        }
        else if (estadosBotones == estadosB::inventario)
        {
            dibujarInventario();
        }
    }
    else{
        cout << "Entre al else" << endl;
    }
}

void Combat::renderizarCombate()
{

    ventana->clear();
    ventana->draw(*spriteCombate);
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
                        if (boton.getId() == "Escapar")
                        {
                            estadosBotones = estadosB::escapar;
                            cout << "Entre a ESCAPAR!" << endl;
                            if (tryEscape())
                            {
                                cout << "Ezakapacion\n";
                                exit(3);
                            }
                            else
                            {
                                cout << "Pa donde vas UwU?\n";
                            }
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
                            //cout << hechizoUsado.getName() << "\n";
                            useAttackSpell(hechizoUsado);

                            
                        }
                        if (boton.getId() == "Habilidad 2")
                        {
                            estadosBotones = estadosB::menu;
                            cout << "Estoy usando habilidad 2!" << endl;
                            useSpell = true;
                            hechizoUsado = player->getSpell(1);
                            //cout << hechizoUsado.getName() << "\n";
                            useAttackSpell(hechizoUsado);
                            cout << "Sali" << endl;

                        }
                        if (boton.getId() == "Habilidad 3")
                        {
                            estadosBotones = estadosB::menu;
                            cout << "Estoy usando habilidad 3!" << endl;
                            useSpell = true;
                            hechizoUsado = player->getSpell(2);
                            //cout << hechizoUsado.getName() << "\n";
                            useAttackSpell(hechizoUsado);

                            
                        }
                        if (boton.getId() == "Habilidad 4")
                        {
                            estadosBotones = estadosB::menu;
                            cout << "Estoy usando habilidad 4!" << endl;
                            useSpell = true;
                            hechizoUsado = player->getSpell(3);
                            //cout << hechizoUsado.getName() << "\n";
                            useAttackSpell(hechizoUsado);
                            cout << "Sali" << endl;

                        
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
        return true;
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

    turnoJugador = false;
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
    turnoJugador = true;
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
        if (i == 3)
        {
            ventana->draw(botonIt->getRect());
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
    fontMensaje->loadFromFile("src/fonts/arial.ttf");
    mensaje.setFont(*fontMensaje);
    mensaje.setPosition(Vector2f(150, 500));
    mensaje.setCharacterSize(20);

    //creamos el mensaje del enemigo

}

void Combat::dibujarMensaje(int personaje)
{
    Clock *reloj;
    Time *cronometro;

    switch (personaje)
    {
    case JUGADOR:
        mensaje.setString(" Haz usado  " + hechizoUsado.getName() + ", hiciste un dahno de: " + to_string(hechizoUsado.getDamage()) + " pts. ");
        useSpell = false;
        break;
        /*case ENEMIGO:
            mensaje.setString(" EL ENEMIGO TE HA ECHO DAÑO  ");
            turnoEnemigo  = false;
            break; */
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

