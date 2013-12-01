#include <thread>
#include <string>

#ifndef TIBIA_BASE_ADDRESS
#define TIBIA_BASE_ADDRESS 0x0400000
#endif // !TIBIA_BASE_ADDRESS

using namespace std;

class TibiaInj
{
public:
	// Variables
	int* exp;

	// Methods
	TibiaInj();
	~TibiaInj();
	int* getExp();
	void TestOutput();

private:
	
};