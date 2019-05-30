#include<iostream>
#include<string>
#include<exception>
using namespace std;
int factorial(int n);
int facT(int n);
int main() 
{
	//用负数、0、1、大于1的数测试factorial函数。
	//四个数可以做到语句覆盖和分支覆盖测试。
	cout << factorial(-1) << endl;
	cout << factorial(0) << endl;
	cout << factorial(1) << endl;
	cout << factorial(5) << endl;
	cout << "-------------------\n";
	//用0、1、2、大于2和负数测试facT函数
	try
	{
		cout << facT(0) << endl;
		cout << facT(1) << endl;
		cout << facT(2) << endl;
		cout << facT(3) << endl;
		cout << facT(-1) << endl;
		system("pause");
		return 0;
	}
	catch (const exception &e)
	{
		cerr << e.what() << endl;
		system("pause");
		return 1;
	}
	
}

int factorial(int n)
{
	if (n <= 1)
		return 1;
	int result = n;
	while (n!=1)
	{
		result = result * (n - 1);
		n = n - 1;
	}
	return result;
}

int facT(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else if (n >= 2)
		return facT(n - 1) + facT(n - 2);
	else
		throw exception("斐波那契数不能为负数");
}
