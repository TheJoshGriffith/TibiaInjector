#include "stdafx.h"
#define v1022
#include "Player.h"
#include "Core.h"
#include <fstream>
#include "Addresses.h"

Player::Player(Core * coar)
{
	core = coar;
	getMyBLPos();
}

Player::~Player(void)
{
	delete core;
}

void Player::setOutfit()
{
	//core->battleList->battleList[blPos].outfit = 100;
}

int* Player::getCID()
{
	return (int *)(Addresses::CID + core->util->BaseAddress);
}

int* Player::getExp()
{
	return (int *)(Addresses::exp + core->util->BaseAddress);
}

void Player::getMyBLPos()
{
	for (int i = 0; i < Addresses::blmax; i++)
	{
		if (* getCID() == * (int *)(Addresses::BLStart + core->util->BaseAddress + i * Addresses::blsize))
		{
			blPos = i;
		}
	}
}

void Player::GoTo(int x, int y, int z)
{
	int gotoAddress = Addresses::BLStart + blPos * Addresses::blsize + Addresses::walkingOffset + core->util->BaseAddress;
	* (int *)(core->util->BaseAddress + Addresses::gotoX) = x;
	* (int *)(core->util->BaseAddress + Addresses::gotoY) = y;
	* (int *)(core->util->BaseAddress + Addresses::gotoZ) = z;
	* (int *)(gotoAddress) = 1;
}