#include "stdafx.h"
#define v1022
#include "Player.h"
#include "Core.h"
#include <fstream>
#include "Addresses.h"

Player::Player(Core * coar)
{
	core = coar;
}

Player::Player(void)
{

}

Player::~Player(void)
{

}

int* Player::getCID()
{
	return (int *)(Addresses::CID + core->util.BaseAddress);
}

int Player::getMyBLPos()
{
	for (int i = 0; i < Addresses::blmax; i++)
	{
		if (* getCID() == * (int *)(Addresses::BLStart + core->util.BaseAddress + i * Addresses::blsize))
		{
			return i;
		}
	}
	return -1;
}

void Player::GoTo(int x, int y, int z)
{
	int blPos = getMyBLPos();
	int gotoAddress = Addresses::BLStart + blPos * Addresses::blsize + Addresses::walkingOffset + core->util.BaseAddress;
	* (int *)(core->util.BaseAddress + Addresses::gotoX) = x;
	* (int *)(core->util.BaseAddress + Addresses::gotoY) = y;
	* (int *)(core->util.BaseAddress + Addresses::gotoZ) = z;
	* (int *)(gotoAddress) = 1;
}