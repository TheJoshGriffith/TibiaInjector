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
#include <string>
#include "Core.h"
#define v1022
#include "Addresses.h"

using namespace std;

// Address of GoToX method: 41A6DA

TibiaInj::TibiaInj()
{
	core = Core();
	WriteDwdToFile("C:\\Users\\Debug\\Desktop\\baseAddress.txt", Util::getBaseAddress());
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