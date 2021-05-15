#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"

#include <map>
using std::map;

class Player : public Entity{
    private:
        int hearts;
        sf::Texture * textures;
        sf::Sprite * sprites;
        //vector<Item> inventory;
        //map<string, Equipment> equipment;
        int mana;
        int xp;
        int resistancePoints;
    public:
        Player( sf::Texture *  textures, sf::Sprite * sprite );
        void updateHealthPoints( int newHealthPoints );
        void updateAttackPoints( int newAttackPoints );
        bool checkDead( );
        bool checkGameOver( );
};

#endif