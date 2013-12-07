#include "Map.h"
#include <cstring>
#include <Windows.h>

#define TIBIA_BASE_ADDRESS 0x1E0000

Tile Map::GetPlayerTile()
{
	 //(0x5EA644 + TIBIA_BASE_ADDRESS)
	
	Tile tiles[2016];
	memcpy(tiles, (void*)(0x5EA644 + TIBIA_BASE_ADDRESS), sizeof(tiles));
	Beep(500,1000);
	unsigned int playerId = *(unsigned int*)0x557034 + TIBIA_BASE_ADDRESS;

	for (int i = 0; i < 2016; i++)
	{
		if (tiles[i].objectCount >= 0)
		{
			for (int j = 0; j < tiles[i].objectCount; j++)
			{
				if (tiles[i].items[j].id == 0x63 && tiles[i].items[j].data == playerId)
					return tiles[i];
			}
		}
	}

	delete tiles;
}