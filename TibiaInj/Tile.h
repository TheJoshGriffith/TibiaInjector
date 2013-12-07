#include "Item.h"

#ifndef TileStruct
#define TileStruct
struct Tile
{
public:
	int objectCount; //0x0
	int padding[0xB]; //0x4
	Item groundItem;//0x30
	Item items[9]; //0x54
	void ReplaceGround(unsigned int id);
	//struct size = 0x198
};
#endif