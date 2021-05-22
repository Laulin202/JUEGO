#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>

#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;
using namespace sf;
using namespace std;
using std::cout;
using std::cin;
using std::endl;

class Tile{
    private:
        
    public:
        int x;
        int y;
        
        Color color;

        Tile(int x, int y, Color color);
};

#endif