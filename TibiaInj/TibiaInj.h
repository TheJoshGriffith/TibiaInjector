#include <thread>
#include <string>

#define TIBIA_BASE_ADDRESS 0x0400000

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