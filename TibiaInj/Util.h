#pragma once
class Util
{
public:
	Util();
	~Util();
	static DWORD getBaseAddress();
	HWND getHwnd();
	BOOL CALLBACK EnumProc(HWND hwnd, LPARAM lParam);
	HWND hwnd;
	DWORD BaseAddress;
	
};

