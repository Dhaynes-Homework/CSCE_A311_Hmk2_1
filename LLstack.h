#pragma once
#include"Calc.h"
class LLstack
{
	public:
		// Constuctor
		LLstack();

		// Destructor
		~LLstack();

		// Functions
		void push(double str);
		void pop();
		bool isEmpty();
		double top();
		double topAndPop();
	private:
		Calc *head;


};

