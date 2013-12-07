#include "stdafx.h"
#include "Util.h"
#include <Windows.h>
#include <Psapi.h>

Util::Util()
{
	BaseAddress = getBaseAddress();
}

Util::~Util()
{

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
/*
static HWND temphwnd;

BOOL CALLBACK Util::EnumProc(HWND hwnd, LPARAM lParam)
{
	if (hwnd == NULL)
    {
        return FALSE;
    }
	TCHAR wn[255];
    int iLen = GetWindowText(hwnd, wn, 255);
    if (IsWindowVisible(hwnd) && iLen > 0)
	{
		MessageBoxA(hwnd, "Wah", "Wahwah", NULL);
		temphwnd = hwnd;
	}
    return TRUE;
}

HWND Util::getHwnd()
{
	DWORD pid = GetCurrentProcessId();
	EnumWindows(Util::EnumProc, (LPARAM)pid);
	hwnd = temphwnd;
}
*/