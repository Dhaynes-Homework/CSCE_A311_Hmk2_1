// Devan Haynes
// CSCE A311 Hmk2_1
// Needs needs calc.*, LLstack.*, and rpnFunc.*

// Used for CSCE A311 Homework Assignment 2 Part 1

// Objective is to make reverse polish notation calculator using a stack

#include<iostream>
#include<string>
#include<sstream>
#include<cmath>
#include"LLstack.h"
#include"rpnFunc.h"

using namespace std;

int main()
{
	string input;
	LLstack stack1;
	string exit;
	
	do
	{
		double result;

		// Taking expression input
		cout << "Please enter your numbers: ";
		getline(cin, input);

		stringstream input_stringstream(input);

		try
		{
			// Parsing string
			while (input_stringstream >> input)
			{
				double num;

				// Checking if input is a Number
				if (istringstream(input) >> num)
				{
					// Throwing Syntax error is number is negative
					if (num < 0)
					{
						throw 1;
						break;
					}
					stack1.push(num);
				}
				// Checking if input is valid operator
				else if (opCheck(input))
				{
					// preform operation
					operation(input, stack1);
				}
				// throwing Syntax error if not a number or operator
				else
				{
					throw 1;
					break;
				}
			}
			// storing final result and checking for extra operands
			result = stack1.topAndPop();
			if (!stack1.isEmpty())
			{
				throw 3;
			}
		}

		// Error catching
		catch (int e)
		{
			if (e == 1)
			{
				cout << "Syntax error, input: " << input << " is not a valid input." << endl;
				system("pause");
				return 0;
			}
			else if (e == 2)
			{
				cout << "Stack underflow error" << endl;
				system("pause");
				return 0;
			}
			else if (e == 3)
			{
				cout << "Too many operands error" << endl;
				system("pause");
				return 0;
			}
			else // e == 4
			{
				cout << "Divide by zero error" << endl;
				system("pause");
				return 0;
			}

		}

		// Final resutls output
		cout << "The anwser is: " << result << endl;

		// User prompt for second expression
		cout << "Would you like to evaluate another expretion. ('E' to exit or any other input to evaluate another)" << endl;
		cin >> exit;
		cin.ignore();
	}
	while (exit != "E");

	return 0;
}