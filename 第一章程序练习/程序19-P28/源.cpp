#include<iostream>
#include<string>
#include<exception>
using namespace std;
//非递归程序计算n!,从n到2
int factorial_one(int n);
//非递归程序计算n!,从2到n
int factorial_two(int n);
//递归函数计算斐波那契数Fn
int facT1(int n);
//非递归函数计算斐波那契数
int facT2(int n);

int main() 
{
	//用负数、0、1、大于1的数测试factorial_one函数。
	//四个数可以做到语句覆盖和分支覆盖测试。
	cout << factorial_one(-1) << endl;
	cout << factorial_one(0) << endl;
	cout << factorial_one(1) << endl;
	cout << factorial_one(5) << endl;
	cout << "-------------------\n";
	//用负数、0、1、大于1的数测试factorial_two函数。
	//四个数可以做到语句覆盖和分支覆盖测试。
	cout << factorial_two(-1) << endl;
	cout << factorial_two(0) << endl;
	cout << factorial_two(1) << endl;
	cout << factorial_two(5) << endl;
	cout << "-------------------\n";
	try
	{
		//用0、1、2、大于2和负数测试facT1函数
		cout << facT1(1) << endl;
		cout << facT1(2) << endl;
		cout << facT1(3) << endl;
		cout << facT1(4) << endl;
		cout << facT1(5) << endl;
		cout << "-------------------\n";
		//用0、1、2、大于2和负数测试facT2函数
		cout << facT2(1) << endl;
		cout << facT2(2) << endl;
		cout << facT2(3) << endl;
		cout << facT2(4) << endl;
		cout << facT2(5) << endl;
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

int factorial_one(int n)
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

int factorial_two(int n)
{
	if (n <= 1)
		return 1;
	int result = 2;
	for (int i = 3; i <= n; i++)
	{
		result *= i;
	}
	return result;
}

int facT1(int n)
{
	if (n==1||n==2)
		return 1;
	else if (n > 2)
		return facT1(n - 1) + facT1(n - 2);
	else
		throw exception("斐波那契数不能小于1");
}

int facT2(int n)
{
	if (n == 1 || n == 2)
		return 1;
	else if (n>2)
	{
		int result = 0;
		int num1 = 1;
		int num2 = 1;
		for (int i = 3; i <= n; i++)
		{
			result = num1 + num2;
			num1 = num2;
			num2 = result;
		}
		return result;
	}
	else
		throw exception("斐波那契数不能小于1");
	
}
