//斐波那契：数列从第3项起，每一项是前两项的和，这就是有名的斐波拉契数列。 
//即a1=a2=0，an=a(n-1)+a(n-2) (n≥3) 
//第0项：0，第一项：1，第二项：前两项之和 
//实现输入n,求出斐波那契的第n项。 
//注：防止数值超过int，应用long long 存储返回值。 

#include<iostream>
using namespace std;
long long Fibonacci(int n)//最优化版，时间复杂度为O(N)，空间复杂度为O(1)。
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
long long Fibonacci1(int n)//递归，斐波那契递归算法时间复杂度：O（2^N）空间复杂度为:O(N)
{
	return n <= 1 ? n : Fibonacci(n - 1) + Fibonacci(n - 2);
}
long long Fibonacci2(int n)//时间复杂度为O(N)。
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