#ifndef ENTITY_H
#define ENTITY_H

#include "Spell.h"
#include <SFML/Graphics.hpp>
#include "SpriteA.h"


#include <string>
#include <vector>
#include <iostream>


using std::string;
using std::vector;
using namespace sf;
using std::cout;
using std::cin;
using std::endl;

class Entity: public SpriteA
{
    protected:
        string name;
        int maxHealthPoints;
        int healthPoints;
        int attackPoints;
        vector <Spell> spells;
        int lvl;
    public:
        Entity();
        ~Entity();
        void updateHealthPoints();
        void updateAttackPoints();
        FloatRect getHitBox(){ return hitBox; }
        RectangleShape getRectangle(){ return *rectangle; };
        int getMaxHealthPoints(){ return this->maxHealthPoints; }
        
};

#endif