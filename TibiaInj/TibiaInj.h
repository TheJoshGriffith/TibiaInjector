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

#ifndef TIBIA_BASE_ADDRESS
#define TIBIA_BASE_ADDRESS 0x0400000
#endif // !TIBIA_BASE_ADDRESS

#ifndef BLSIZE
#define BLSIZE 0xC0
#endif

#ifndef BLSTART
#define BLSTART 0x005AD478
#endif

#ifndef BLMAX
#define BLMAX 1400
#endif

#ifndef WALKINGOFFSET
#define WALKINGOFFSET 0x050
#endif

class TibiaInj
{
public:
	// Variables
	int* exp;

	// Methods
	TibiaInj();
	~TibiaInj();
	void TestOutput();

	// Getter Methods
	int* getExp();
	int* getCID();
	int getMyBLPos();

	// Setter Methods
	void GoTo(int x, int y, int z);	

private:
	
};