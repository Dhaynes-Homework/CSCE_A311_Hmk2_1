#include "Calc.h"


// Constructors
Calc::Calc()
{
	next = nullptr;
	stored = 0;
}

Calc::Calc(double str)
{
	stored = str;
}

Calc::Calc(Calc *n, double str)
{
	next = n;
	stored = str;
}

// Destructor
Calc::~Calc()
{
}

//Accessors
Calc* Calc::nextCalc()
{
	return next;
}

double Calc::getStored()
{
	return stored;
}