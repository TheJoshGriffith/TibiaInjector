#ifndef UTIL_H
#define UTIL_H

class Core;

class Util
{
public:
	Util(Core * coar);
	~Util();
	static DWORD getBaseAddress();
	DWORD BaseAddress;
	Core * core;
};
#endif