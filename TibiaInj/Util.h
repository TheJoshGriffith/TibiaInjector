#ifndef UTIL_H
#define UTIL_H

class Core;

class Util
{
public:
	Util(Core *);
	~Util();
	DWORD getBaseAddress();
	HWND getHwnd();
	DWORD BaseAddress;
	HWND hwnd;
	HANDLE handle;
	Core * core;
};
#endif