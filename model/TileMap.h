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
#include <map>

using std::string;
using std::vector;
using namespace sf;
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using std::multimap;

class TileMap : public Drawable{
    protected:
        Texture* tileset;
        VertexArray* vertexArray;
        vector<FloatRect> tilesArray;
        multimap<int, Vector2f> bloqueosTiles;
        multimap<int, FloatRect> bloqueosTilesHitbox;
        int arrayPos = 0;
        int width;
        int height;
        Vector2f tileSize;
        float tileTextureDimension;
        float tileWorldDimension;
        
    public:
        TileMap(Texture* tileSet, int w, int h, float tileTexDim, float tileWorldDim);
        void addTileVertices(Tile tile, Vector2f position, int enemyKey = 0);
        vector<vector<int>> loadTiles();
        void updateBlockedTiles( int key );
        void draw(RenderTarget& window, RenderStates states) const override { states.texture = tileset; window.draw(*vertexArray, states); };
        VertexArray* getArray(){ return vertexArray; };
        vector<FloatRect> getTilesArray(){ return tilesArray; };
        multimap<int, FloatRect> getBloqueosHitbox(){ return bloqueosTilesHitbox; };
        Vector2f getTileSize(){ return tileSize; }
        int getWidth(){ return width; };
        int getHeight(){ return height; };
};




#endif 