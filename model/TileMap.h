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
        /*
        Nombre: Tilemap
        Output: N/A
        Input: Texture, Int, Int, Float, Float
        Funcion: Construye Tilemap, generando el vertexArray de Tiles y agregando mediante un ciclo cada Tile.
        */
        TileMap(Texture* tileSet, int w, int h, float tileTexDim, float tileWorldDim);

        /*
        Nombre: addTileVertices
        Output: N/A
        Input: Tile, Vector2f, Int
        Funcion: Agrega el tile enviado a la posicion especificada en el vertexArray, y de paso se evalua si este Tile genera alguna colision o no, esto mediante el color del Tile y para agregarlo o no al arreglo de los Tiles con bloqueo.
        */
        void addTileVertices(Tile tile, Vector2f position, int enemyKey = 0);

        /*
        Nombre: loadTiles
        Output: vector<vector<int>>
        Input: N/A
        Funcion: Carga la base del vertexArray con los tiles especificados desde un archivo .txt.
        */
        vector<vector<int>> loadTiles();

        /*
        Nombre: updateBlockedTiles
        Output: N/A
        Input: Int
        Funcion: Actualiza los tiles de bloqueo que ya no deberian generar este, actualizandolos visualmente y eliminandolos de los que se deben evaluar por colision.
        */
        void updateBlockedTiles( int key );

        /*
        Nombre: draw
        Output: N/A
        Input: RenderTarget, RenderStates
        Funcion: Coloca la textura indicada en los archivos y la carga en el vertexArray.
        */
        void draw(RenderTarget& window, RenderStates states) const override { states.texture = tileset; window.draw(*vertexArray, states); };

        VertexArray* getArray(){ return vertexArray; }; // Retorna el vertexArray
        vector<FloatRect> getTilesArray(){ return tilesArray; }; // Retorna el arreglo de Tiles
        multimap<int, FloatRect> getBloqueosHitbox(){ return bloqueosTilesHitbox; }; // Retorna el multimap de los tiles con bloqueo
        Vector2f getTileSize(){ return tileSize; } // Retorna el tamanio de cada tile
        int getWidth(){ return width; }; // Retorna el ancho del mapa
        int getHeight(){ return height; }; // Retorna el alto del mapa
};




#endif 