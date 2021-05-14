#ifndef SPELL_H
#define SPELL_H


#include <string>
using std::string;

class Spell{
    private:
        string name;
        string description;
        int manaCost;
    public:
        void useSpell();
};

#endif