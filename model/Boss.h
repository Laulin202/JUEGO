#ifndef BOSS_H
#define BOSS_H
#include "Enemy.h"

class Boss : Enemy{
    private:
        int effectPoints;
    public:
        void giveEffect();
};


#endif