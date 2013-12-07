#ifndef CORE_H
#define CORE_H

#include "Util.h"
#include "BattleList.h"
#include "Map.h"
#include "Tile.h"
#include "Player.h"
#include "Addresses.h"


class Core
{
public:
	Core::Core(void);
	Core::~Core(void);
	Util * util;
	BattleList * battleList;
	Map * map;
	Player * player;
};
#endif