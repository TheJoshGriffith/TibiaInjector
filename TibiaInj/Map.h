#ifndef MAP_H
#define MAP_H

#include "Tile.h"
#include <vector>

class Map
{
public:
	Tile GetPlayerTile();
	Tile *(tiles[2016]);
	std::vector<Tile*> GetTiles();
private:
	
};

#endif