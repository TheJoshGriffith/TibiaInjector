/*
	GetModuleName.cpp

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
#include <string>
#include <iostream>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	HWND hwnd = FindWindow(L"TibiaClient", NULL);
	cout << "Handle: " << hwnd << endl;
	DWORD cbNeeded;
	DWORD processID;
	GetWindowThreadProcessId(hwnd, &processID);
	cout << "Process ID: " << processID << endl;
	HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, TRUE, processID);
	cout << "Process Handle: " << handle << endl;
	HMODULE hMods[1024];
	if (EnumProcessModules(handle, hMods, sizeof(hMods), &cbNeeded))
	{
		cout << "Enumerated: " << "Success!" << endl;
		for (int i = 0; i < (cbNeeded / sizeof(hwnd)); i++)
		{
			cout << "Round " << i << ": ";
			TCHAR szModName[MAX_PATH];
			if (GetModuleFileNameEx(handle, hMods[i], szModName, sizeof(szModName) / sizeof(TCHAR)))
			{
				cout << "Module Name: ";
				wcout << szModName; // Wide string char thing
				cout << ". Entry Number: " << hMods[i] ; // hMods may be wide string, too, IDK, I didn't use it yet.
			}
			cout << ". " << endl;
		}
	}
	CloseHandle(handle);
	cout << "End" << endl;
	cin.get();
	return 0;
}

