#include "Cycles.h"

Cycles::Cycles()
{
	this->Counter = 0;
	this->RetCounter = 0;
	this->CurrentCount = 0;
	this->LastCount = 0;
}
Cycles::~Cycles(){ }

void Cycles::Count()
{
	this->CurrentCount = clock() * 0.001f;
	this->Counter++;

	if((this->CurrentCount - this->LastCount) > 1.0f)
	{
	    this->LastCount = this->CurrentCount;
		this->RetCounter = this->Counter;
		//sprintf(str, format, this->Counter);
	    this->Counter = 0;
	} 
}

int Cycles::GetCount()
{
	return this->RetCounter;
}