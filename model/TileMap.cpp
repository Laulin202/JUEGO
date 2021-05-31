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
    Color color;
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
            if(tiles[y][x] == 84 || tiles[y][x] == 20 || tiles[y][x] == 34 || tiles[y][x] == 48 || tiles[y][x] == 62 || tiles[y][x] == 76 || tiles[y][x] == 77 || tiles[y][x] == 78 || tiles[y][x] == 79 || tiles[y][x] == 80 || tiles[y][x] == 81 || tiles[y][x] == 67 || tiles[y][x] == 53 || tiles[y][x] == 39 || tiles[y][x] == 25 || tiles[y][x] == 0 || tiles[y][x] == 1 || tiles[y][x] == 2 || tiles[y][x] == 3 || tiles[y][x] == 4 || tiles[y][x] == 5 || tiles[y][x] == 14 || tiles[y][x] == 28 || tiles[y][x] == 42 || tiles[y][x] == 56 || tiles[y][x] == 70 || tiles[y][x] == 71 || tiles[y][x] == 72 || tiles[y][x] == 73 || tiles[y][x] == 75 || tiles[y][x] == 74 || tiles[y][x] == 47 || tiles[y][x] == 33 ){
                color = Color::Black;
            }else{
                color = Color::White;
            }
            Tile tile = Tile((int)(fmod(tiles[y][x], (tileSet->getSize().x / tileWorldDimension))), (int)(tiles[y][x] / (tileSet->getSize().x / tileWorldDimension)), color);
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
    Tile bloq1 = Tile(3,9,Color::Red);
    Tile bloq2 = Tile(4,9,Color::Red);
    Tile bloq3 = Tile(5,9,Color::Red);
    addTileVertices(bloq1, Vector2f((float)32, (float)32));
    addTileVertices(bloq2, Vector2f((float)33, (float)32));
    bloqueosTiles.insert(pair <int, Vector2f> (8, Vector2f((float)32, (float)32)));
    bloqueosTiles.insert(pair <int, Vector2f> (8, Vector2f((float)33, (float)32)));

    addTileVertices(bloq1, Vector2f((float)31, (float)52));
    addTileVertices(bloq2, Vector2f((float)32, (float)52));
    addTileVertices(bloq1, Vector2f((float)33, (float)52));
    addTileVertices(bloq2, Vector2f((float)34, (float)52));
    bloqueosTiles.insert(pair <int, Vector2f> (5, Vector2f((float)31, (float)52)));
    bloqueosTiles.insert(pair <int, Vector2f> (5, Vector2f((float)32, (float)52)));
    bloqueosTiles.insert(pair <int, Vector2f> (5, Vector2f((float)33, (float)52)));
    bloqueosTiles.insert(pair <int, Vector2f> (5, Vector2f((float)34, (float)52)));

    addTileVertices(bloq3, Vector2f((float)17, (float)60));
    addTileVertices(bloq3, Vector2f((float)17, (float)61));
    bloqueosTiles.insert(pair <int, Vector2f> (4, Vector2f((float)17, (float)60)));
    bloqueosTiles.insert(pair <int, Vector2f> (4, Vector2f((float)17, (float)61)));

    addTileVertices(bloq3, Vector2f((float)17, (float)76));
    addTileVertices(bloq3, Vector2f((float)17, (float)77));
    bloqueosTiles.insert(pair <int, Vector2f> (2, Vector2f((float)17, (float)76)));
    bloqueosTiles.insert(pair <int, Vector2f> (2, Vector2f((float)17, (float)77)));

    addTileVertices(bloq3, Vector2f((float)47, (float)60));
    addTileVertices(bloq3, Vector2f((float)47, (float)61));
    bloqueosTiles.insert(pair <int, Vector2f> (3, Vector2f((float)47, (float)60)));
    bloqueosTiles.insert(pair <int, Vector2f> (3, Vector2f((float)47, (float)61)));

    addTileVertices(bloq3, Vector2f((float)47, (float)76), 1);
    addTileVertices(bloq3, Vector2f((float)47, (float)77), 1);
    bloqueosTiles.insert(pair <int, Vector2f> (1, Vector2f((float)47, (float)76)));
    bloqueosTiles.insert(pair <int, Vector2f> (1, Vector2f((float)47, (float)77)));

    addTileVertices(bloq3, Vector2f((float)103, (float)38));
    addTileVertices(bloq3, Vector2f((float)103, (float)39));
    addTileVertices(bloq3, Vector2f((float)103, (float)40));
    addTileVertices(bloq3, Vector2f((float)103, (float)41));
    bloqueosTiles.insert(pair <int, Vector2f> (6, Vector2f((float)103, (float)38)));
    bloqueosTiles.insert(pair <int, Vector2f> (6, Vector2f((float)103, (float)39)));
    bloqueosTiles.insert(pair <int, Vector2f> (6, Vector2f((float)103, (float)40)));
    bloqueosTiles.insert(pair <int, Vector2f> (6, Vector2f((float)103, (float)41)));

    addTileVertices(bloq1, Vector2f((float)82, (float)22));
    bloqueosTiles.insert(pair <int, Vector2f> (7, Vector2f((float)82, (float)22)));
    /*
    addTileVertices(leftTopCorner, Vector2f((float)0, (float)0));
    addTileVertices(leftBottomCorner, Vector2f((float)0, (float)height-1));
    addTileVertices(rightTopCorner, Vector2f((float)width-1, (float)0));
    addTileVertices(rightBottomCorner, Vector2f((float)width-1, (float)height-1));
    */
}

void TileMap::addTileVertices(Tile tile, Vector2f position, int enemyKey){
    vertexArray->append(Vertex((Vector2f(0.0f, 0.0f) + position) * tileWorldDimension, Vector2f(tileTextureDimension * tile.x, tileTextureDimension * tile.y))); // Esquina superior izquierda

    vertexArray->append(Vertex((Vector2f(1.0f, 0.0f) + position) * tileWorldDimension, Vector2f(tileTextureDimension * tile.x + tileTextureDimension, tileTextureDimension * tile.y))); // Esquina superior derecha

    vertexArray->append(Vertex((Vector2f(1.0f, 1.0f) + position) * tileWorldDimension, Vector2f(tileTextureDimension * tile.x + tileTextureDimension, tileTextureDimension * tile.y + tileTextureDimension))); // Esquina inferior derecha

    vertexArray->append(Vertex((Vector2f(0.0f, 1.0f) + position) * tileWorldDimension, Vector2f(tileTextureDimension * tile.x, tileTextureDimension * tile.y + tileTextureDimension))); // Esquina inferior izquierda

    if(tile.color == Color::Black){
        FloatRect tileBox;
        tileBox = FloatRect((Vector2f(0.0f, 0.0f) + position) * tileWorldDimension, Vector2f(tileWorldDimension, tileWorldDimension));
        tilesArray.push_back(tileBox);
    }
    else if(tile.color == Color::Red){
        FloatRect tileBox;
        tileBox = FloatRect((Vector2f(0.0f, 0.0f) + position) * tileWorldDimension, Vector2f(tileWorldDimension, tileWorldDimension));
        bloqueosTilesHitbox.insert(pair <int, FloatRect> (enemyKey, tileBox));
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

void TileMap::updateBlockedTiles( int key ){
    multimap<int, Vector2f>::iterator positions = bloqueosTiles.find( key );
    int number = bloqueosTiles.count( key );
    Tile floor(2, 2, Color::White);
    for(int i = 0; i < number; i++){
        addTileVertices(floor, positions->second);
        ++positions;
    }
    bloqueosTiles.erase(key);
}