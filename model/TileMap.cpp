#include "TileMap.h"

TileMap::TileMap(Texture* tileSet, int w, int h, float tileTexDim, float tileWorldDim){
    tileset = tileSet;
    width = w;
    height = h;
    tileTextureDimension = tileTexDim;
    tileWorldDimension = tileWorldDim;
    vertexArray = new VertexArray(PrimitiveType::Quads, (uint)(width * height));
    tileSize = Vector2f(tileWorldDim, tileWorldDim);
    vector<vector<int>> tiles;
    tiles = loadTiles();
    /*
    Tile floor = Tile(1, 1, Color::White);
    Tile path = Tile(7, 0, Color::Black);
    Tile topFloor = Tile(1, 0, Color::White);
    Tile bottomFloor = Tile(1, 2, Color::White);
    Tile leftFloor = Tile(0, 1, Color::White);
    Tile rightFloor = Tile(2, 1, Color::White);
    Tile leftTopCorner = Tile(0, 0, Color::White);
    Tile leftBottomCorner = Tile(0, 2, Color::White);
    Tile rightTopCorner = Tile(2, 0, Color::White);
    Tile rightBottomCorner = Tile(2, 2, Color::White);
    */
    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            Tile tile = Tile((int)(fmod(tiles[y][x], (tileSet->getSize().x / tileWorldDimension))), (int)(tiles[y][x] / (tileSet->getSize().x / tileWorldDimension)), Color::White);
            addTileVertices(tile, Vector2f((float)x, (float)y));
            /*
            addTileVertices(floor, Vector2f((float)x, (float)y));
            if(y == 5){
                addTileVertices(path, Vector2f((float)x, (float)5));
            }
            if((y == 0) || (y == (height - 1)) || (x == 0) || ( x == (width - 1))){
                addTileVertices(topFloor, Vector2f((float)x, (float)0));
                addTileVertices(bottomFloor, Vector2f((float)x, (float)height-1));
                addTileVertices(leftFloor, Vector2f((float)0, (float)y));
                addTileVertices(rightFloor, Vector2f((float)width-1, (float)y));
                
            }*/
        }
    }
    /*
    addTileVertices(leftTopCorner, Vector2f((float)0, (float)0));
    addTileVertices(leftBottomCorner, Vector2f((float)0, (float)height-1));
    addTileVertices(rightTopCorner, Vector2f((float)width-1, (float)0));
    addTileVertices(rightBottomCorner, Vector2f((float)width-1, (float)height-1));
    */
}

void TileMap::addTileVertices(Tile tile, Vector2f position){
    vertexArray->append(Vertex((Vector2f(0.0f, 0.0f) + position) * tileWorldDimension, Vector2f(tileTextureDimension * tile.x, tileTextureDimension * tile.y))); // Esquina superior izquierda

    vertexArray->append(Vertex((Vector2f(1.0f, 0.0f) + position) * tileWorldDimension, Vector2f(tileTextureDimension * tile.x + tileTextureDimension, tileTextureDimension * tile.y))); // Esquina superior derecha

    vertexArray->append(Vertex((Vector2f(1.0f, 1.0f) + position) * tileWorldDimension, Vector2f(tileTextureDimension * tile.x + tileTextureDimension, tileTextureDimension * tile.y + tileTextureDimension))); // Esquina inferior derecha

    vertexArray->append(Vertex((Vector2f(0.0f, 1.0f) + position) * tileWorldDimension, Vector2f(tileTextureDimension * tile.x, tileTextureDimension * tile.y + tileTextureDimension))); // Esquina inferior izquierda

    if(tile.color == Color::Black){
        FloatRect tileBox;
        tileBox = FloatRect((Vector2f(0.0f, 0.0f) + position) * tileWorldDimension, Vector2f(tileWorldDimension, tileWorldDimension));
        tilesArray.push_back(tileBox);
    }
}

vector<vector<int>> TileMap::loadTiles(){
    vector<vector<int> > tiles;
    ifstream map_stream("src/images/tileset/map.txt");
    
    for (string line; getline(map_stream, line);){
        tiles.push_back(vector<int>());
        stringstream line_stream(line);
        copy(istream_iterator<int>(line_stream), istream_iterator<int>(), back_inserter(tiles.back()));
    }
    /*
    if ( !map_stream.is_open () ){
    cout << "Error: Could not open file\n" << endl;
    }
    int current = 0;
    for ( int y = 0; y < height; y++ )
    {
        // Create a new vector to store the values of each row 
        std::vector<int> row;

        for ( int x = 0; x < width; x++ )
        {
            if ( map_stream.eof () )
            {
                cout << "Reached end of file %s too early. Check width and height parameters.\n" << endl;
            }

            // Capturing the value stored at the current location within the text file.
            map_stream >> current;

            // Checking if the input is valid tile type (0 - 23)
            if( current >= 0 && current <= 23 )
            {
                row.push_back ( current );
            }
            // If the input isnt a valid tile type it is filled with 0
            else
            {
                row.push_back (0);
            }
        }
        tiles.push_back ( row );
    }
    */
    map_stream.close ();
    return tiles;
}