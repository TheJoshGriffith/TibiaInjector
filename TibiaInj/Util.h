#ifndef UTIL_H
#define UTIL_H

class Core;

class Util
{
public:
	Util(Core * coar);
	~Util();
	DWORD getBaseAddress();
	HWND getHwnd();
	DWORD BaseAddress;
	HWND hwnd;
	HANDLE handle;
	Core * core;
};
#endif