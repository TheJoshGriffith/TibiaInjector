#include "stdafx.h"
#include "Util.h"
#include <Windows.h>
#include <Psapi.h>
#include <fstream>
#include "Core.h"

Util::Util(Core * coar)
{
	core = coar;
	BaseAddress = getBaseAddress();
	getHwnd();
}

Util::~Util()
{
	delete core;
}

DWORD Util::getBaseAddress() // Gets the base address of the first module. This is typically the client, never found it to be anything else.
{
	DWORD cbNeeded;
	HANDLE pHandle;
	pHandle = GetCurrentProcess();
	HMODULE hMods[1024];
	if (EnumProcessModules(pHandle, hMods, sizeof(hMods), &cbNeeded))
	{
		return (DWORD)hMods[0];
	}
	return 0;
}

HWND hwndtemp;

BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam)
{
	DWORD pid;
	GetWindowThreadProcessId(hwnd, &pid);
	if (pid = GetCurrentProcessId())
	{
		hwndtemp = hwnd;
	}
	return 1;
}


HWND Util::getHwnd()
{
	EnumWindows(EnumWindowsProc, NULL);
	return hwndtemp;
}