#include<iostream>
using namespace std;
//�������Ķ����ƴ洢�ص�
int OneBitNum(int num)
{
	int ret = 0;
	while (num)
	{
		++ret;
		num = num&(num - 1);
	}
	return ret;
}
void Test1()
{
	cout << OneBitNum(9) << endl;//2
	cout << OneBitNum(0) << endl;//0
	cout << OneBitNum(5) << endl;//2
	cout << OneBitNum(2) << endl;//1
	cout << OneBitNum(15) << endl;//4
}