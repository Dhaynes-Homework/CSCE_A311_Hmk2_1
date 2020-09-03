#include "LLstack.h"

// Constructor
LLstack::LLstack()
{
	head = nullptr;
}

// Destructor
LLstack::~LLstack()
{
}

// Functions
void LLstack::push(double str)
{

	Calc *temp;
	temp = new Calc(head, str);
	head = temp;

	return;
}

void LLstack::pop()
{
	if (isEmpty())
	{
		return;
	}
	Calc *temp;
	temp = head;
	head = head->nextCalc();
	delete temp;
	return;
}

double LLstack::top()
{
	if (isEmpty())
	{
		return -1;
	}
	return head->getStored();
}

double LLstack::topAndPop()
{
	double t = top();
	pop();
	return t;
}

bool LLstack::isEmpty()
{
	if (head == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}