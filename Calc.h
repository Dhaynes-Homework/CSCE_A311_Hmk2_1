#pragma once
#include<iostream>

using namespace std;

class Calc
{
	public:
		// Constructors
		Calc();
		Calc(double str);
		Calc(Calc *n, double str);

		// Destructor
		~Calc();

		//Accessors
		Calc* nextCalc();
		double getStored();

	private:
		Calc *next;
		double stored;
};

