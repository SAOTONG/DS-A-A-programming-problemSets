// function to compute an expression using int value parameters
// throw an exception of type illegalParameterValue
// in case one of the parameters is <= 0

#include<iostream>
#include "myExceptions.h"

using namespace std;

int abc(int a, int b, int c)
{
	if (a < 0 && b < 0 && c < 0)
		throw 1;
	else if (a == 0 && b == 0 && c == 0)
		throw 2;
	else
		return a + b * c;
}

int main()
{
	try { cout << abc(2, 0, 4) << endl; }
	catch (int e)
	{
		cout << "The parameters to abc were 2, 0, and 4" << endl;
		cout << "An exception has been thrown" << endl;
		cout << e << endl;
		system("pause");
		return 1;
	}
	system("pause");
	return 0;
}
