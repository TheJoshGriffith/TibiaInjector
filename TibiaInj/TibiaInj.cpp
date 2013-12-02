/*
	TibiaInj.cpp

	© Josh Griffith 2013
	
	This file is part of GenericInjector.

    Foobar is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Foobar is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "stdafx.h"
#include <Windows.h>
#include <Psapi.h>
#include <fstream>
#include "TibiaInj.h"
#include <thread>
#include <string>

using namespace std;

// Address of GoToX method: 41A6DA

TibiaInj::TibiaInj()
{
	TestOutput();	
}

TibiaInj::~TibiaInj()
{

}

void TibiaInj::TestOutput()
{
	exp = getExp();
	ofstream ostr;
	ostr.open("C:\\Users\\Debug\\Desktop\\output.txt");
	ostr << "This round" << endl;
	for (int i = 0; i < 30; i++)
	{
		ostr << "Experience (exp): " << *exp << endl;
		Sleep(1000);
	}
	ostr.close();
}

int* TibiaInj::getExp()
{
	return (int *)(0x03C2280 + TIBIA_BASE_ADDRESS);
}