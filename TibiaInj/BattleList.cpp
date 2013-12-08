#include "stdafx.h"
#include "BattleList.h"
#include "Core.h"
#define v1022
#include "Addresses.h"

using namespace std;

typedef Creature battleListType[1300];

BattleList::BattleList(Core * coar)
{
	core = coar;
	for (int i = 0; i < Addresses::blmax; i++)
	{
		DWORD offset = i * Addresses::blsize;
		battleList[i] = (Creature *)(Addresses::BLStart + core->util->BaseAddress + offset);
	}
}


BattleList::~BattleList(void)
{
}

void BattleList::DumpBattleList(char* fileName)
{
	ofstream sw;
	
	sw.open(fileName);
	for (int i = 0; i < 1300; i++)
	{
		sw << "CID: " << (*battleList)[i].cid << ". Name: " << (*battleList)[i].name << ". HPPC: " << (*battleList)[i].hpPc << endl; 
	}
	sw.close();
}
