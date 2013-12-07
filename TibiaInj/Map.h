#ifndef MAP_H
#define MAP_H

#include "Core.h"
#include "Tile.h"
#include <vector>

class Map
{
public:
	Map(Core *core);
	Tile GetPlayerTile();
	Tile *(tiles[2016]);
	std::vector<Tile*> GetTiles();
private:
	Core *core;
};

#endif