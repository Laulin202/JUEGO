#include "TileMap.h"

TileMap::TileMap(Texture* tileSet, int w, int h, float tileTexDim, float tileWorldDim){
    tileset = tileSet;
    width = w;
    height = h;
    tileTextureDimension = tileTexDim;
    tileWorldDimension = tileWorldDim;
    vertexArray = new VertexArray(PrimitiveType::Quads, (uint)(width * height));

    Tile grass = Tile(0, 1, Color::White);
    Tile path = Tile(1, 1, Color::White);
    Tile yerba = Tile(2, 2, Color::White);
    Tile cartel = Tile(0, 0, Color::White);
    for(int x = 0; x < width; x++){
        for(int y = 0; y < height; y++){
            addTileVertices(grass, Vector2f((float)x, (float)y));
            addTileVertices(yerba, Vector2f((float)x, (float)4));
            addTileVertices(path, Vector2f((float)x, (float)5));
            addTileVertices(yerba, Vector2f((float)x, (float)6));
        }
    }
    addTileVertices(cartel, Vector2f((float)0, (float)3));
}

void TileMap::addTileVertices(Tile tile, Vector2f position){
    vertexArray->append(Vertex((Vector2f(0.0f, 0.0f) + position) * tileWorldDimension, Vector2f(tileTextureDimension * tile.x, tileTextureDimension * tile.y))); // Esquina superior izquierda

    vertexArray->append(Vertex((Vector2f(1.0f, 0.0f) + position) * tileWorldDimension, Vector2f(tileTextureDimension * tile.x + tileTextureDimension, tileTextureDimension * tile.y))); // Esquina superior derecha

    vertexArray->append(Vertex((Vector2f(1.0f, 1.0f) + position) * tileWorldDimension, Vector2f(tileTextureDimension * tile.x + tileTextureDimension, tileTextureDimension * tile.y + tileTextureDimension))); // Esquina inferior derecha

    vertexArray->append(Vertex((Vector2f(0.0f, 1.0f) + position) * tileWorldDimension, Vector2f(tileTextureDimension * tile.x, tileTextureDimension * tile.y + tileTextureDimension))); // Esquina inferior izquierda
}