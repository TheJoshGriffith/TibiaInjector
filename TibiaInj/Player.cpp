#include "stdafx.h"
#include "Player.h"

Player::Player(Core *core)
{
	this->core = core;
}

Player::~Player(void)
{

}

DWORD Player::GetZ()
{
	//return *(DWORD*)SOMEADDRESS + core->getBaseAddress();
	return 0;
}