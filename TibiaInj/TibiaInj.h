/*
	TibiaInj.h

	© Josh Griffith 2013
	
	This file is part of TibiaInjector.

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

#include <thread>
#include <string>

#ifndef TIBIA_BASE_ADDRESS
#define TIBIA_BASE_ADDRESS 0x0400000
#endif // !TIBIA_BASE_ADDRESS

using namespace std;

class TibiaInj
{
public:
	// Variables
	int* exp;

	// Methods
	TibiaInj();
	~TibiaInj();
	int* getExp();
	void TestOutput();

private:
	
};