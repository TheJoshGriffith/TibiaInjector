#ifndef MAP_H
#define MAP_H

#include "stdafx.h"
#include "Tile.h"
#include <vector>

class Core;

class Map
{
public:
	Map::Map(Core *);
	Map::Map();
	Map::~Map();
	Tile GetPlayerTile();
	Tile *(tiles[2016]);
	std::vector<Tile*> GetTiles();
private:
	Core * Coar;
};
#endif