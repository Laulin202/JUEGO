#ifndef COMBAT_H
#define COMBAT_H
#include "Player.h"
#include "Enemy.h"
#include "Boss.h"

enum{
    PLAYERWON = true, ENEMYWON = false
};

class Combat
{
    private:
        Player * player;
        Enemy * enemy;
        int turn;
    public:
        bool isOver( );
        bool whoWon();
};


#endif
