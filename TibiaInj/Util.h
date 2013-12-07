#ifndef UTIL_H
#define UTIL_H
class Util
{
public:
	Util();
	~Util();
	static DWORD getBaseAddress();
	DWORD BaseAddress;
};
#endif