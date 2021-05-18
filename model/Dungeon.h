#ifndef DUNGEON_H
#define DUNGEON_H
#include "Room.h"

class Dungeon
{
    private:
        Room * dungeon;
        int dungeonSize;
        int startingRoom[2];
        int exitRoom[2];
        int artifactRoom[2];
    public:
        void openExitRoom();
};

#endif