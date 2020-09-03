#include "rpnFunc.h"

// Checking if input is valid operator
bool opCheck(const string& op)
{
	if (op == "+")
		return true;
	else if (op == "-")
		return true;
	else if (op == "*")
		return true;
	else if (op == "/")
		return true;
	else if (op == "sqrt")
		return true;
	else
		return false;
}

// Funtion for valid operations
void operation(const string& op, LLstack& stack1)
{
	double firstNum;
	double secondNum;

	// Addition
	// All check for if there are enough operands
	if (op == "+")
	{
		secondNum = stack1.topAndPop();
		firstNum = stack1.topAndPop();
		if (secondNum < 0 || firstNum < 0)
		{
			throw 2;
			return;
		}
		firstNum += secondNum;
		stack1.push(firstNum);
	}

	// Subtraction
	else if (op == "-")
	{
		secondNum = stack1.topAndPop();
		firstNum = stack1.topAndPop();
		if (secondNum < 0 || firstNum < 0)
		{
			throw 2;
			return;
		}
		firstNum -= secondNum;
		stack1.push(firstNum);
	}

	// Multiplication
	else if (op == "*")
	{
		secondNum = stack1.topAndPop();
		firstNum = stack1.topAndPop();
		if (secondNum < 0 || firstNum < 0)
		{
			throw 2;
			return;
		}
		firstNum *= secondNum;
		stack1.push(firstNum);
	}

	// Division
	else if (op == "/")
	{
		secondNum = stack1.topAndPop();
		firstNum = stack1.topAndPop();
		if (secondNum < 0 || firstNum < 0)
		{
			throw 2;
			return;
		}
		if (secondNum == 0)   //Check for divide by zero
		{
			throw 4;
			return;
		}
		firstNum /= secondNum;
		stack1.push(firstNum);
	}

	// Square root
	else // (op == "sqrt")
	{
		firstNum = stack1.topAndPop();
		if (firstNum < 0)
		{
			throw 2;
			return;
		}
		firstNum = sqrt(firstNum);
		stack1.push(firstNum);
	}
	return;
}