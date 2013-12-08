#include "stdafx.h"
#include "Core.h"


Core::Core(void)
{
	util = &Util(this);
	battleList = &BattleList(this);
	player = &Player(this);
	map = &Map(this);
}

Core::~Core(void)
{
	delete util;
	delete battleList;
	delete player;
	delete map;
}
