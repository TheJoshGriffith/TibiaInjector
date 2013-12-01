// TibiaInj.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include <Windows.h>
#include <Psapi.h>
#include <fstream>
#include "TibiaInj.h"
#include <thread>
#include <string>

using namespace std;

// Address of GoToX method: 41A6DA

TibiaInj::TibiaInj()
{
	TestOutput();	
}

TibiaInj::~TibiaInj()
{

}

void TibiaInj::TestOutput()
{
	exp = getExp();
	ofstream ostr;
	ostr.open("C:\\Users\\Debug\\Desktop\\output.txt");
	ostr << "This round" << endl;
	for (int i = 0; i < 30; i++)
	{
		ostr << "Experience (exp): " << *exp << endl;
		Sleep(1000);
	}
	ostr.close();
}

int* TibiaInj::getExp()
{
	return (int *)(0x03C2280 + TIBIA_BASE_ADDRESS);
}