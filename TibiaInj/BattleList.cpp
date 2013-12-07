#include "stdafx.h"
#include "BattleList.h"
#include <fstream>

using namespace std;

typedef BattleList::Creature battleListType[1300];

BattleList::BattleList(void)
{
	* battleList = *(battleListType*)(0x5AD478 + 0x400000);
	ofstream ofs;
	ofs.open("C:\\Users\\Debug\\Desktop\\BLoutput.txt");
	// char newname[32] = "Penis\0                         ";
	// (*battleList)[0].name = newname; // Doesn't work due to left operand not being l-value
	ofs << "Battle list read: " << (*battleList)[0].name << endl;
	ofs.close();
}


BattleList::~BattleList(void)
{
}
