#include <time.h>

class Cycles
{

public:
	Cycles();
	~Cycles();

	void Count();
	int GetCount();

private:
	int Counter;
	int RetCounter;
	float LastCount;
	float CurrentCount;

};
