#include<iostream>
#include<string>
#include<exception>
using namespace std;
int factorial(int n);
int facT(int n);
int main() 
{
	//�ø�����0��1������1��������factorial������
	//�ĸ�������������串�Ǻͷ�֧���ǲ��ԡ�
	cout << factorial(-1) << endl;
	cout << factorial(0) << endl;
	cout << factorial(1) << endl;
	cout << factorial(5) << endl;
	cout << "-------------------\n";
	//��0��1��2������2�͸�������facT����
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
		throw exception("쳲�����������Ϊ����");
}
