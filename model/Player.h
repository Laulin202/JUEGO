#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"

#include <map>
using std::map;

class Player : Entity{
    private:
        int hearts;
        //vector<Item> inventory;
        //map<string, Equipment> equipment;
        int mana;
        int xp;
        int resistancePoints;
    public:
        void updateHealthPoints( int newHealthPoints );
        void updateAttackPoints( int newAttackPoints );
        bool checkDead( );
};

#endif