#ifndef TILEMAP_H
#define TILEMAP_H

#include <SFML/Graphics.hpp>
#include "Tile.h"

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

class TileMap : public Drawable{
    protected:
        Texture* tileset;
        VertexArray* vertexArray;

        int width;
        int height;
        float tileTextureDimension;
        float tileWorldDimension;
        
    public:
        TileMap(Texture* tileSet, int w, int h, float tileTexDim, float tileWorldDim);
        void addTileVertices(Tile tile, Vector2f position);
        void draw(RenderTarget& window, RenderStates states) const override { states.texture = tileset; window.draw(*vertexArray, states); };
        VertexArray* getArray(){ return vertexArray; };


};




#endif 