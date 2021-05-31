#ifndef WEAPON_H
#define WEAPON_H
#include "Equipment.h"

class Weapon : public Equipment
{
    private:
        int bonusAttackPoints;
    public:
        Weapon(string name, string description, int numWeapon, int bonusAttack, Vector2f position);
        void setTexture(int numWeapon); // Se coloca la textura
};

#endif