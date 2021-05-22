#include "Combat.h"



Combat::Combat(){

}

Combat::Combat(RenderWindow& ventana, Player& player){
    this->ventana = &ventana;
    this->player = &player;
}


void Combat::iniciarRectangulos(){
    for( int i = 0; i < 8; i++){

        String id = "";
        RectangleShape* r = new RectangleShape({120,40});
        r->setFillColor(Color::Blue);
        
        switch (i)
        {
        case 0:
             r->setPosition( 48, 450);
             r->setSize(Vector2f(90,40));
             id = "Atacar";
            
            break;

        case 1:
            r->setPosition( 48, 498);
            r->setSize(Vector2f(90,40));
            id = "Inventario";
            break;

        case 2:
            r->setPosition( 48, 546);
            r->setSize(Vector2f(90,40));
            id = "Escapar";
            break;

        case 3:
            r->setPosition( 200, 546);
            r->setSize(Vector2f(60,40));
            id = "Menu";
            break;

        case 4:
            r->setPosition( 200, 450);
            id = "Habilidad 1";
            break;
        case 5:
            r->setPosition( 350, 450);
            id = "Habilidad 2";
            break;
        case 6:
            r->setPosition( 200, 498);
            id = "Habilidad 3";
            break;
        case 7:
            r->setPosition( 350, 498);
            id = "Habilidad 4";
            break;
        default:
            break;
        }
        listaOpciones.push_back(Button( id, *r));

    }
}


void Combat::renderPanelOpciones(){
    
    if(turnoJugador){
        if (estadosBotones == estadosB::menu){
            if (useSpell){
                dibujarMensaje();
            }
            dibujarMenuPrincipal();
        }
        else if (estadosBotones == estadosB::atacar){
            dibujarMenuHabilidades();
        }
        else if( estadosBotones == estadosB::inventario){
            dibujarInventario();
        }   
    }
    
}

void Combat::renderizarCombate(){

    ventana->clear();
    ventana->draw(*spriteCombate);
    renderPanelOpciones();
    ventana->display();


}

void Combat::procesarEventosCombate(){
    while(ventana->pollEvent(*evento1)){
        switch (evento1->type){
            case Event::Closed:
                exit(1);
                break;

            case Event::MouseButtonReleased:
                if(evento1->mouseButton.button == Mouse::Left){
                    Vector2i posMouse;
                    posMouse = Mouse::getPosition(*ventana);

                    for(Button boton: listaOpciones ){

                        if(boton.getRect().getGlobalBounds().contains(posMouse.x, posMouse.y)){
                            
                            if(boton.getId() == "Atacar"){
                                estadosBotones = estadosB::atacar;
                                cout << "Entre a atacar!" << endl;
                            }
                            if(boton.getId() == "Inventario"){
                                estadosBotones = estadosB::inventario;
                                cout << "Entre a INVENTARIO!" << endl;
                            }
                            if(boton.getId() == "Escapar"){
                                estadosBotones = estadosB::escapar;
                                cout << "Entre a ESCAPAR!" << endl;
                            } 
                            if(boton.getId() == "Menu"){
                                estadosBotones = estadosB::menu;
                                cout << "Volvi a menu!" << endl;
                            }
                            if(boton.getId() == "Habilidad 1"){
                                estadosBotones = estadosB::menu;
                                cout << "Estoy usando habilidad 1!" << endl;
                                useSpell = true;
                                hechizoUsado = player->getSpell();
                                cout << "Sali" << endl;
                                
                            }
                            if(boton.getId() == "Habilidad 2"){
                                estadosBotones = estadosB::menu;
                                cout << "Estoy usando habilidad 2!" << endl;
                                
                            }
                            if(boton.getId() == "Habilidad 3"){
                                estadosBotones = estadosB::menu;
                                cout << "Estoy usando habilidad 3!" << endl;
                                
                            }
                            if(boton.getId() == "Habilidad 4"){
                                estadosBotones = estadosB::menu;
                                cout << "Estoy usando habilidad 4!" << endl;
                                
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

void Combat::procesarLogicaCombate(){
    procesarEventosCombate();
    //falta mas logica
}


void Combat::dibujarMenuPrincipal(){
    int i = 0;
    for(list<Button>::iterator botonIt = listaOpciones.begin(); botonIt != listaOpciones.end(); botonIt ++ ){
        if(i < 3){
            ventana->draw(botonIt->getRect());  
        }
        i++;
    }

}

void Combat::dibujarInventario(){
    int i = 0;
    for(list<Button>::iterator botonIt = listaOpciones.begin(); botonIt != listaOpciones.end(); botonIt ++ ){
        if(i == 3){
            ventana->draw(botonIt->getRect());
            break;
        }
        i++;   
    }
}

void Combat::dibujarMenuHabilidades(){
    int i = 0;
    for(list<Button>::iterator botonIt = listaOpciones.begin(); botonIt != listaOpciones.end(); botonIt ++ ){
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

void Combat::iniciarComponentesCombate(){
    texturaBackground = new Texture();
    texturaBackground->loadFromFile("src/images/textureCombate/Captura.png");
    spriteCombate = new Sprite(*texturaBackground);
    iniciarRectangulos();
    evento1 = new Event();
    opcion = 1;

    fontMensaje = new Font();

    fontMensaje->loadFromFile("src/fonts/arial.ttf");
    mensaje.setFont(*fontMensaje);
    mensaje.setPosition(Vector2f(200,500));
    mensaje.setCharacterSize(20);
}


void Combat::dibujarMensaje(){
    Clock* reloj;
    Time* cronometro;

    reloj = new Clock();
    cronometro = new Time();

    mensaje.setString(" Haz usado la habilidad "+ hechizoUsado.getName() + ", hiciste un dahno de: " + to_string(hechizoUsado.getDamage()));
    mensaje.setFillColor(Color::Black);

     //Tiempo transcurrido
    while(reloj->getElapsedTime().asSeconds() < 7.f ){ //Evaluar un cronometro de segundos 
        ventana->draw(mensaje);
        ventana->display();
    }
    useSpell = false;
}