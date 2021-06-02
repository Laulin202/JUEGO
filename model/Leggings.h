#ifndef LEGGINGS_H
#define LEGGINGS_H
#include "Equipment.h"

class Leggings : public Equipment
{
    private:
        int bonusResistancePoints;
    public:
        Leggings(string name, string description, int numLeggings, int bonusResistance, Vector2f position);
        void setTexture(int numLeggings); // Coloca la textura
};

#endif