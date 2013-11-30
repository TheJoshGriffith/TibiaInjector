// TibiaInj.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include <Windows.h>
#include <Psapi.h>
#include <fstream>
#include "TibiaInj.h"

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
	ostr << "New Attempt" << endl;
	ostr << "Experience (exp): " << exp << endl;
	ostr.close();
}

int TibiaInj::getExp()
{
	return * (int *)(0x03C2280 + 0x0400000);
}