#ifndef CHESTPLATE_H
#define CHESTPLATE_H
#include "Equipment.h"

class Chestplate : public Equipment
{
    private:
        int bonusResistancePoints;
    public:
        Chestplate(string name, string description, int numArmor, int bonusResistance, Vector2f position);
        void setTexture(int numArmor); // Se coloca la textura
};

#endif