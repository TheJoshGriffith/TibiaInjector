#include "stdafx.h"
#include "Util.h"
#include <Windows.h>
#include <Psapi.h>

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