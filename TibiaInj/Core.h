#pragma once

#include "Util.h"
#include "BattleList.h"
#include "Map.h"
#include "Tile.h"


class Core
{
public:
	Core(void);
	~Core(void);
	Util util;
	BattleList battleList;
	Map map;
};

