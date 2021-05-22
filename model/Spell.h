#ifndef SPELL_H
#define SPELL_H


#include <SFML/Graphics.hpp>


#include <iostream>
#include <string>
using std::string;
using namespace sf;
using std::cout;
using std::cin;
using std::endl;

class Spell{
    private:
        String name;
        String description;
        int damage;
        int manaCost;
    public:
        Spell();
        Spell( String name, String description, int damage, int manaCost);
        int getDamage(){ return damage; }
        String getName(){ return name; }
        void useSpell();
};

#endif