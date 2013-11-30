// GetBaseAddrCpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <Psapi.h>
#include <iostream>
#include <fstream>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	wofstream myFile;
	myFile.open("modules.txt");
	myFile.clear();
	myFile << L"Josh's module finder" << endl;
	HWND hwnd = FindWindow(L"TibiaClient", NULL);
	cout << "Handle: " << hwnd << endl;
	myFile << L"Handle: " << hwnd << endl;
	DWORD cbNeeded;
	DWORD processID;
	GetWindowThreadProcessId(hwnd, &processID);
	cout << "Process ID: " << processID << endl;
	myFile << L"Process ID: " << processID << endl;
	HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, TRUE, processID);
	cout << "Process Handle: " << handle << endl;
	myFile << L"Process Handle: " << handle << endl;
	HMODULE hMods[1024];
	if (EnumProcessModules(handle, hMods, sizeof(hMods), &cbNeeded))
	{
		cout << "Enumerated: " << "Success!" << endl;
		for (int i = 0; i < (cbNeeded / sizeof(hwnd)); i++)
		{
			cout << "Round " << i << ": ";
			myFile << L"Round " << i << L": ";
			TCHAR szModName[MAX_PATH];
			if (GetModuleFileNameEx(handle, hMods[i], szModName, sizeof(szModName) / sizeof(TCHAR)))
			{
				cout << "Module Name: ";
				wcout << szModName; // Wide string char thing
				cout << ". Entry Number: " << hMods[i] ; // hMods may be wide string, too, IDK, I didn't use it yet.
				myFile << L"Module Name: " << szModName << L". Entry Number: " << hMods[i];
			}
			cout << ". " << endl;
			myFile << L". " << endl;
		}
	}
	CloseHandle(handle);
	cout << "End" << endl;
	myFile.close();
	return 0;
}

