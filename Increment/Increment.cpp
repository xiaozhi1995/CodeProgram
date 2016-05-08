#include<iostream>
using namespace std;
int Increment(char num[], int len)
{
	int isOverFlow = 0;//是否溢出
	int isTake = 0;//是否发生进位
	for (int i = len - 1; i >= 0; --i)
	{
		if (i == len - 1)
		{
			num[i]++;
			if (num[i] == 10)
			{
				num[i] = 0;
				isTake = 1;
				if (i == 0)
				{
					isOverFlow = 1;
				}
			}
		}
		else if (i == 0)
		{
			if (num[i] + isTake == 10)
			{
				isOverFlow = 1;
				break;
			}
			else
			{
				num[i] += isTake;
			}
		}
		else
		{
			if (num[i] + isTake == 10)
			{
				num[i] = 0;
				isOverFlow = 1;
			}
			else
			{
				num[i] += isTake;
				break;
			}
		}
	}
	return isOverFlow;
}
void PrintNum(char num[], int len)
{
	/*int flag = 1;
	for (int i = 0; i < len; ++i)
	{
		if (flag&&num[i] == 0)
			continue;
		else
			flag = 0;
		if (flag == 0)
			printf("%d", num[i]);
	}*/
	cout << endl;
}
void Test1()
{
	char num[10] = { 0 };
	int len = 2;//最大输入9
	cin >> len;
	while (!Increment(num, len))
	{
		PrintNum(num, len);
	}
}
#include<iostream>
using namespace std;
bool Increment(char num[], int len)
{
	bool isOverFlow = false;
	int isTake = 0;
	int sum = 0;
	for (int i = len - 1; i >= 0; --i)
	{
		sum = num[i] - '0' + isTake;
		if (i == len - 1)
			sum++;
		if (sum >= 10)
		{
			if (i == 0)
			{
				isOverFlow = true;
			}
			else
			{
				sum -= 10;
				isTake = 1;
				num[i] = sum+'0';
			}
		}
		else
		{
			num[i]=sum+'0';
			break;
		}
	}
	return isOverFlow;
}
void PrintNum(char num[], int len)
{
	int flag = 1;
	for (int i = 0; i < len; ++i)
	{
		if (flag&&num[i] == '0')
			continue;
		else
			flag = 0;
		if (flag == 0)
			printf("%c", num[i]);
	}
	cout << endl;
}
void Test1()
{
	char num[10];
	memset(num, '0', sizeof(num) / sizeof(num[0]));
	num[9] = '\0';
	int len = 0;
	cin >> len;
	while (!Increment(num, len))
	{
		PrintNum(num, len);
	}
}

#include<iostream>
using namespace std;
void PrintNum(char num[], int len)
{
	int flag = 1;
	for (int i = 0; i < len; ++i)
	{
		if (flag&&num[i] == '0')
			continue;
		else
			flag = 0;
		if (flag == 0)
			printf("%c", num[i]);
	}
	cout << endl;
}
void PrintMaxOfDigitRecursive(char* num, int length, int index)
{
	if (index == length - 1)
	{
		PrintNum(num, length);
		return;
	}
	for (int i = 0; i < 10; ++i)
	{
		num[index + 1] = i + '0';
		PrintMaxOfDigitRecursive(num, length, index + 1);
	}
}
void PrintMaxOfDigit(int n)
{
	if (n <= 0)
		return;
	char *num = new char[n + 1];
	num[n] = '\0';
	for (int i = 0; i < 10; ++i)
	{
		num[0] = i + '0';
		PrintMaxOfDigitRecursive(num, n, 0);
	}
	delete[] num;
}
void Test1()
{
	int len;
	cin >> len;
	PrintMaxOfDigit(len);
}