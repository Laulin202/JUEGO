#ifndef TILEMAP_H
#define TILEMAP_H

#include <SFML/Graphics.hpp>
#include "Tile.h"

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <math.h>

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
        vector<FloatRect> tilesArray;
        int arrayPos = 0;
        int width;
        int height;
        Vector2f tileSize;
        float tileTextureDimension;
        float tileWorldDimension;
        
    public:
        TileMap(Texture* tileSet, int w, int h, float tileTexDim, float tileWorldDim);
        void addTileVertices(Tile tile, Vector2f position);
        vector<vector<int>> loadTiles();
        void draw(RenderTarget& window, RenderStates states) const override { states.texture = tileset; window.draw(*vertexArray, states); };
        VertexArray* getArray(){ return vertexArray; };
        vector<FloatRect> getTilesArray(){ return tilesArray; };
        Vector2f getTileSize(){ return tileSize; }
        int getWidth(){ return width; };
        int getHeight(){ return height; };
};




#endif 