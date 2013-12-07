#include "stdafx.h"
#include "Core.h"


Core::Core(void)
{
	Player plyr(this);
	Util utl(this);
	BattleList bl(this);
	Map mp(this);
	util = &utl;
	battleList = &bl;
	player = &plyr;
	map = &mp;
}

Core::~Core(void)
{
	delete util;
	delete battleList;
	delete player;
	delete map;
}
