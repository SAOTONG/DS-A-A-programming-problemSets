//���ļ�����28ҳ19��20��21��Ĵ���ʵ��
//��Ҫ�Եݹ麯���ͷǵݹ麯����ʵ��
//�ܽᷢ��������ѧ��ʽ��������ʹ�õݹ麯���Ƚ�����
//����д�ǵݹ麯������Ҫ�۲첢����������ɽ��н��
#include<iostream>
#include<string>
#include<exception>
using namespace std;

//�ǵݹ�������n!
//�ų�0��1�͸������n��2����,p28ҳ19��
int non_recursive_factorial_one(int n);
//�ǵݹ�������n!
//�ų�0��1�͸������2��n����,p28ҳ19��
int non_recursive_factorial_two(int n);
//�ݹ麯������쳲�������Fn,p28ҳ20��
int recursive_fibonacci(int n);
//�ǵݹ麯������쳲�������,p28ҳ20��
int non_recursive_fibonacci(int n);
//�ݹ麯������p28ҳ21��
int recursive_page28_21(int n);
//�ǵݹ麯������p28ҳ21��
int non_recursive_page28_21(int n);

int main() 
{
	//�ø�����0��1������1��������factorial_one������
	//�ĸ�������������串�Ǻͷ�֧���ǲ��ԡ�
	cout << non_recursive_factorial_one(-1) << endl;
	cout << non_recursive_factorial_one(0) << endl;
	cout << non_recursive_factorial_one(1) << endl;
	cout << non_recursive_factorial_one(5) << endl;
	cout << "-------------------\n";
	//�ø�����0��1������1��������factorial_two������
	//�ĸ�������������串�Ǻͷ�֧���ǲ��ԡ�
	cout << non_recursive_factorial_two(-1) << endl;
	cout << non_recursive_factorial_two(0) << endl;
	cout << non_recursive_factorial_two(1) << endl;
	cout << non_recursive_factorial_two(5) << endl;
	cout << "-------------------\n";
	try
	{
		//��0��1��2������2�͸�������facT1����
		//���������������串�Ǻͷ�֧���ǲ��ԡ�
		cout << recursive_fibonacci(0) << endl;
		cout << recursive_fibonacci(1) << endl;
		cout << recursive_fibonacci(2) << endl;
		cout << recursive_fibonacci(3) << endl;
		cout << recursive_fibonacci(-1) << endl;
		cout << "-------------------\n";
		//��0��1��2������2�͸�������facT2����
		//���������������串�Ǻͷ�֧���ǲ��ԡ�
		cout << non_recursive_fibonacci(0) << endl;
		cout << non_recursive_fibonacci(1) << endl;
		cout << non_recursive_fibonacci(2) << endl;
		cout << non_recursive_fibonacci(3) << endl;
		cout << non_recursive_fibonacci(-1) << endl;
		cout << "-------------------\n";
		//ʹ����������������Կ���������串�Ǻͷ�֧���ǲ��ԡ�
		cout << recursive_page28_21(0) << endl;
		cout << recursive_page28_21(2) << endl;
		cout << recursive_page28_21(4) << endl;
		cout << recursive_page28_21(1) << endl;
		cout << recursive_page28_21(3) << endl;
		cout << recursive_page28_21(5) << endl;
		cout << recursive_page28_21(-1) << endl;
		cout << "-------------------\n";
		//ʹ����������������Կ���������串�Ǻͷ�֧���ǲ��ԡ�
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
		cout << "�������г�����\n";
		cerr << "������ϢΪ:" << e.what() << endl;
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
		throw exception("쳲�����������С��1");
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
		throw exception("쳲�����������С��1");
	
}

//������븺�����׳��쳣���������С�������ضϡ�
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
		throw exception("��������Ϊ����");
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
		throw exception("��������Ϊ����");
}
