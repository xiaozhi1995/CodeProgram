//쳲����������дӵ�3����ÿһ����ǰ����ĺͣ������������쳲��������С� 
//��a1=a2=0��an=a(n-1)+a(n-2) (n��3) 
//��0�0����һ�1���ڶ��ǰ����֮�� 
//ʵ������n,���쳲������ĵ�n� 
//ע����ֹ��ֵ����int��Ӧ��long long �洢����ֵ�� 

#include<iostream>
using namespace std;
long long Fibonacci(int n)//���Ż��棬ʱ�临�Ӷ�ΪO(N)���ռ临�Ӷ�ΪO(1)��
{
	long long num1 = 0;
	long long num2 = 1;
	if (n <= 1)
		return n;
	int count = n - 1;
	long long sum = 0;
	while (count--)
	{
		sum = num1 + num2;
		num1 = num2;
		num2 = sum;
	}
	return num2;
}
long long Fibonacci1(int n)//�ݹ飬쳲������ݹ��㷨ʱ�临�Ӷȣ�O��2^N���ռ临�Ӷ�Ϊ:O(N)
{
	return n <= 1 ? n : Fibonacci(n - 1) + Fibonacci(n - 2);
}
long long Fibonacci2(int n)//ʱ�临�Ӷ�ΪO(N)��
{
	long long *arr = new long long[n+1];
	arr[0] = 0;
	arr[1] = 1;
	int index = 2;
	while (index<=n)
	{
		arr[index] = arr[index - 1] + arr[index - 2];
		++index;
	}
	return arr[n];
}
void Test1()
{
	cout << Fibonacci(3) << endl;
	cout << Fibonacci(5) << endl;
	cout << Fibonacci(1) << endl;
	cout << Fibonacci(10) << endl;
	cout << Fibonacci(30) << endl;
}