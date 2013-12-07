#include "stdafx.h"
#include "BattleList.h"

using namespace std;

typedef Creature battleListType[1300];

BattleList::BattleList(void)
{
	* battleList = *(battleListType*)(0x5AD478 + 0x400000);
}

BattleList::BattleList(Core * coar)
{
	core = coar;
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
