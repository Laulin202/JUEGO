#ifndef HELMET_H
#define HELMET_H
#include "Equipment.h"

class Helmet : public Equipment
{
    private:
        int bonusResistancePoints;
    public:
        Helmet(string name, string description, int numHelmet, int bonusResistance, Vector2f position);
        void setTexture(int numHelmet);
};

#endif