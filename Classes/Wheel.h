#include <cstdlib>
#include <ctime>

class Wheel
{
public:
	Wheel();
	void spin();
	int* read();

private:
	int slots[9];
	int internalPtr;
};