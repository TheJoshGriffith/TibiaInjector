#include "stdafx.h"
#include "Core.h"


Core::Core(void)
{
	util = Util();
	battleList = BattleList(); 
	map = new Map(this);
	player = new Player(this);
}


Core::~Core(void)
{

}
