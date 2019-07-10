// evaluate a polynomial using Horner's rule

#include <iostream>
#include <algorithm> // has copy
#include <iterator>
using namespace std;

//数组为多项式的系数序列，n为最大阶数，x为变量
template<class T>
T polyEval(T coeff[], int n, const T& x)
{
	T y = 1;
	T value = coeff[0];
	for (int i = 1; i <= n; i++)
	{
		cout << y << "*" << x << "=";
		y *= x;	
		cout << y << endl;
		cout << value << "+" << y << "*" << coeff[i] << "=";
		value += y * coeff[i];
		cout << value << endl;
	}
	return value;
}

template<class T>
T horner(T coeff[], int n, const T& x)
{// Evaluate the degree n polynomial with
 // coefficients coeff[0:n] at the point x.
	T value = coeff[n];
	for (int i = 1; i <= n; i++)
	{
		cout << value << "*" << x << "+" << coeff[n - i]<< "=";
		value = value * x + coeff[n - i];
		cout << value << endl;
	}
		
	return value;
}

int main()
{
	int a[6] = { 1, 2, 3, 4, 5, 6 };

	// output the coefficients
	cout << "The coefficients a[0:5] are ";
	copy(a, a + 6, ostream_iterator<int>(cout, " "));
	cout << endl;

	cout << "The value at 2 is " << horner(a, 5, 2) << endl;
	cout << "The value at 1 is " << horner(a, 5, 1) << endl;
	cout << "The value at 0 is " << horner(a, 5, 0) << endl;
	system("pause");
	return 0;
}