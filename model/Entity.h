#ifndef ENTITY_H
#define ENTITY_H

#include "Spell.h"


#include <string>
#include <vector>
using std::string;
using std::vector;

class Entity
{
    private:
        string name;
        int healthPoints;
        int attackPoints;
        vector <Spell> spells;
        int lvl;
    public:
        void updateHealthPoints();
        void updateAttackPoints();
};

#endif