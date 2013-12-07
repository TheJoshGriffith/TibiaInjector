#include "stdafx.h"
#include "Core.h"


Core::Core(void)
{
	util = Util();
	battleList = BattleList();
	map = Map(this);
	player = Player(this);
}


Core::~Core(void)
{

}
