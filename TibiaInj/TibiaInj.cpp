/*
	TibiaInj.cpp

	© Josh Griffith 2013
	
	This file is part of GenericInjector.

    TibiaInjector is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    TibiaInjector is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with TibiaInjector.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "stdafx.h"
#include <Windows.h>
#include <Psapi.h>
#include <fstream>
#include "TibiaInj.h"
#include <thread>
#include <string>
#include "BattleList.h"
#include "Util.h"

using namespace std;

// Address of GoToX method: 41A6DA

UINT gotoX = 0x557030;
UINT gotoY = 0x557028;
UINT gotoZ = 0x557004;

TibiaInj::TibiaInj()
{
	WriteDwdToFile("C:\\Users\\Debug\\Desktop\\baseAddress.txt", Util::getBaseAddress());
	bl = BattleList();
	bl.DumpBattleList("C:\\Users\\Debug\\Desktop\\bloutput.txt");
	TestOutput();
	GoTo(32369, 32242, 6);
}

TibiaInj::~TibiaInj()
{

}

void TibiaInj::WriteStrToFile(char* file, char* text)
{
	ofstream ostr;
	ostr.open(file);
	ostr << text;
	ostr.close();
}

void TibiaInj::WriteDwdToFile(char* file, DWORD dwd)
{
	ofstream ostr;
	ostr.open(file);
	ostr << dwd;
	ostr.close();
}

void TibiaInj::TestOutput()
{
	exp = getExp();
	int* oldexp = getExp();
	ofstream ostr;
	ostr.open("C:\\Users\\Debug\\Desktop\\output.txt");
	ostr << "Experience (exp): " << *exp << endl;
	ostr << "CID             : " << *getCID() << endl;
	//ostr << bl.battleList[0].name << endl;
	ostr.close();
}

int* TibiaInj::getExp()
{
	return (int *)(0x03C2280 + TIBIA_BASE_ADDRESS);
}

int* TibiaInj::getCID()
{
	return (int *)(0x0557034 + TIBIA_BASE_ADDRESS);
}

int TibiaInj::getMyBLPos()
{
	for (int i = 0; i < BLMAX; i++)
	{
		if (* getCID() == * (int *)(BLSTART + TIBIA_BASE_ADDRESS + i * BLSIZE))
		{
			return i;
		}
	}
	return -1;
}

void TibiaInj::GoTo(int x, int y, int z)
{
	ofstream ostr;
	ostr.open("C:\\Users\\Debug\\Desktop\\memread.txt");
	int blPos = getMyBLPos();
	int gotoAddress = BLSTART + blPos * BLSIZE + WALKINGOFFSET + TIBIA_BASE_ADDRESS;
	ostr << gotoAddress << endl;
	* (int *)(TIBIA_BASE_ADDRESS + gotoX) = x;
	* (int *)(TIBIA_BASE_ADDRESS + gotoY) = y;
	* (int *)(TIBIA_BASE_ADDRESS + gotoZ) = z;
	* (int *)(gotoAddress) = 1;
	ostr.close();
}