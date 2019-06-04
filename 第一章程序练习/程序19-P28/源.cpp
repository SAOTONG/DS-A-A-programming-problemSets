#include<iostream>
#include<string>
#include<exception>
using namespace std;
//�ǵݹ�������n!,��n��2
int factorial_one(int n);
//�ǵݹ�������n!,��2��n
int factorial_two(int n);
//�ݹ麯������쳲�������Fn
int facT1(int n);
//�ǵݹ麯������쳲�������
int facT2(int n);

int main() 
{
	//�ø�����0��1������1��������factorial_one������
	//�ĸ�������������串�Ǻͷ�֧���ǲ��ԡ�
	cout << factorial_one(-1) << endl;
	cout << factorial_one(0) << endl;
	cout << factorial_one(1) << endl;
	cout << factorial_one(5) << endl;
	cout << "-------------------\n";
	//�ø�����0��1������1��������factorial_two������
	//�ĸ�������������串�Ǻͷ�֧���ǲ��ԡ�
	cout << factorial_two(-1) << endl;
	cout << factorial_two(0) << endl;
	cout << factorial_two(1) << endl;
	cout << factorial_two(5) << endl;
	cout << "-------------------\n";
	try
	{
		//��0��1��2������2�͸�������facT1����
		cout << facT1(1) << endl;
		cout << facT1(2) << endl;
		cout << facT1(3) << endl;
		cout << facT1(4) << endl;
		cout << facT1(5) << endl;
		cout << "-------------------\n";
		//��0��1��2������2�͸�������facT2����
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
		throw exception("쳲�����������С��1");
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
		throw exception("쳲�����������С��1");
	
}
