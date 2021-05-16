#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"


#include <map>
using std::map;

class Player : public Entity{
    private:
        int hearts;
        Texture* texturesPlayer;
        Sprite* spritesPlayer;
        //vector<Item> inventory;
        //map<string, Equipment> equipment;
        int mana;
        int xp;
        int resistancePoints;
    public:
        Player();
        void inicializarTexturaPlayer();
        void dibujarPlayerPantalla( RenderWindow* ventanaJuego ); //pendiente mover a los privados
        void updateHealthPoints( int newHealthPoints );
        void updateAttackPoints( int newAttackPoints );
        bool checkDead( );
        bool checkGameOver( );
        bool spritesTime(Time elapsed1);
        int playerMovement( RenderWindow* ventanaJuego );
        void playerUpdatePosition(sf::Vector2f pos);
};

#endif