#include <Windows.h>		

#ifdef v1022

#ifndef ADDRESSES
#define ADDRESSES
class Addresses
{
public:
	static const DWORD Player = 0x0557034;
	static const DWORD BLStart = 0x05AD478;
	static const DWORD CID = 0x0557034;
	static const DWORD gotoX = 0x557030;
	static const DWORD gotoY = 0x557028;
	static const DWORD gotoZ = 0x557004;
	static const DWORD walkingOffset = 0x050;
	static const DWORD blsize = 0xC0;
	static const DWORD blmax = 1300;
	static const DWORD exp = 0x03C2280;
};
#endif

#endif