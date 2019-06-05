//该文件包括28页19、20、21题的代码实现
//主要对递归函数和非递归函数的实现
//总结发现在有数学公式的问题上使用递归函数比较容易
//而编写非递归函数则需要观察并分析计算规律进行解决
#include<iostream>
#include<string>
#include<exception>
using namespace std;

//非递归程序计算n!
//排除0、1和负数后从n到2计算,p28页19题
int non_recursive_factorial_one(int n);
//非递归程序计算n!
//排除0、1和负数后从2到n计算,p28页19题
int non_recursive_factorial_two(int n);
//递归函数计算斐波那契数Fn,p28页20题
int recursive_fibonacci(int n);
//非递归函数计算斐波那契数,p28页20题
int non_recursive_fibonacci(int n);
//递归函数计算p28页21题
int recursive_page28_21(int n);
//非递归函数计算p28页21题
int non_recursive_page28_21(int n);

int main() 
{
	//用负数、0、1、大于1的数测试factorial_one函数。
	//四个数可以做到语句覆盖和分支覆盖测试。
	cout << non_recursive_factorial_one(-1) << endl;
	cout << non_recursive_factorial_one(0) << endl;
	cout << non_recursive_factorial_one(1) << endl;
	cout << non_recursive_factorial_one(5) << endl;
	cout << "-------------------\n";
	//用负数、0、1、大于1的数测试factorial_two函数。
	//四个数可以做到语句覆盖和分支覆盖测试。
	cout << non_recursive_factorial_two(-1) << endl;
	cout << non_recursive_factorial_two(0) << endl;
	cout << non_recursive_factorial_two(1) << endl;
	cout << non_recursive_factorial_two(5) << endl;
	cout << "-------------------\n";
	try
	{
		//用0、1、2、大于2和负数测试facT1函数
		//五个数可以做到语句覆盖和分支覆盖测试。
		cout << recursive_fibonacci(0) << endl;
		cout << recursive_fibonacci(1) << endl;
		cout << recursive_fibonacci(2) << endl;
		cout << recursive_fibonacci(3) << endl;
		cout << recursive_fibonacci(-1) << endl;
		cout << "-------------------\n";
		//用0、1、2、大于2和负数测试facT2函数
		//五个数可以做到语句覆盖和分支覆盖测试。
		cout << non_recursive_fibonacci(0) << endl;
		cout << non_recursive_fibonacci(1) << endl;
		cout << non_recursive_fibonacci(2) << endl;
		cout << non_recursive_fibonacci(3) << endl;
		cout << non_recursive_fibonacci(-1) << endl;
		cout << "-------------------\n";
		//使用这个几个参数测试可以做到语句覆盖和分支覆盖测试。
		cout << recursive_page28_21(0) << endl;
		cout << recursive_page28_21(2) << endl;
		cout << recursive_page28_21(4) << endl;
		cout << recursive_page28_21(1) << endl;
		cout << recursive_page28_21(3) << endl;
		cout << recursive_page28_21(5) << endl;
		cout << recursive_page28_21(-1) << endl;
		cout << "-------------------\n";
		//使用这个几个参数测试可以做到语句覆盖和分支覆盖测试。
		cout << non_recursive_page28_21(0) << endl;
		cout << non_recursive_page28_21(2) << endl;
		cout << non_recursive_page28_21(4) << endl;
		cout << non_recursive_page28_21(1) << endl;
		cout << non_recursive_page28_21(3) << endl;
		cout << non_recursive_page28_21(5) << endl;
		cout << non_recursive_page28_21(-1) << endl;
		cout << "-------------------\n";
		system("pause");
		return 0;
	}
	catch (const exception &e)
	{
		cout << "程序运行出错！！\n";
		cerr << "错误信息为:" << e.what() << endl;
		system("pause");
		return 1;
	}
	
}

int non_recursive_factorial_one(int n)
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

int non_recursive_factorial_two(int n)
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

int recursive_fibonacci(int n)
{
	if (n==1||n==2)
		return 1;
	else if (n > 2)
		return recursive_fibonacci(n - 1) + recursive_fibonacci(n - 2);
	else
		throw exception("斐波那契数不能小于1");
}

int non_recursive_fibonacci(int n)
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

//如果输入负数则抛出异常，如果输入小数则发生截断。
int recursive_page28_21(int n)
{
	if (n >= 0)
	{
		if (n % 2 == 0)
			return n / 2;
		else
			return recursive_page28_21(3 * n + 1);
	}
	else
		throw exception("参数不能为负数");
}

int non_recursive_page28_21(int n)
{
	if (n >= 0)
	{
		while (true)
		{
			if (n % 2 == 0)
				return n / 2;
			else
				n = 3 * n + 1;
		}
	}
	else
		throw exception("参数不能为负数");
}
