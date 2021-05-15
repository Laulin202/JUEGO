#ifndef ENTITY_H
#define ENTITY_H

#include "Spell.h"
#include <SFML/Graphics.hpp>


#include <string>
#include <vector>
#include <iostream>


using std::string;
using std::vector;
using namespace sf;
using std::cout;
using std::cin;
using std::endl;

class Entity
{
    protected:
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