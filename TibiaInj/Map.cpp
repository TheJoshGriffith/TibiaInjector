#include "stdafx.h"
#include "Map.h"

#define TIBIA_BASE_ADDRESS 0xF10000
#define MAP_POINTER 0x5EA644

typedef Tile tileType[2016];

Map::Map(Core * coar)
{
	core = coar;
}

Map::~Map()
{
	delete core;
}

Tile Map::GetPlayerTile()
{
	int realPointer = *(int*)(MAP_POINTER + TIBIA_BASE_ADDRESS);
	*tiles = *(tileType*)(realPointer);
	
	unsigned int playerId = *(unsigned int*)(0x557034 + TIBIA_BASE_ADDRESS);
	
	for (int i = 0; i < 2016; i++)
	{
		if (((*tiles)[i].objectCount - 1) >= 0)
		{
			for (int j = 0; j < (*tiles)[i].objectCount - 1; j++)
			{
				if ((*tiles)[i].items[j].id == 0x63 && (*tiles)[i].items[j].data == playerId)
					return (*tiles)[i];
			}
		}
	}
	delete [] &tiles;
}

std::vector<Tile*> GetTiles()
{
	//TODO::
	//Need a player class or something to retrieve the players Z location
}

