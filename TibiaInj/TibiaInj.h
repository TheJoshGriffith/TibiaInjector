/*
	TibiaInj.h

	© Josh Griffith 2013
	
	This file is part of TibiaInjector.

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

#include <thread>
#include <string>
#include "BattleList.h"
#include "Core.h"

class TibiaInj
{
public:
	// Variables
	int* exp;

	// Methods
	TibiaInj();
	~TibiaInj();
	void WriteStrToFile(char* file, char* text);
	void WriteDwdToFile(char* file, DWORD dwd);

	// Class Instances
	Core core;

private:
	
};