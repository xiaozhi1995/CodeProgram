#include<iostream>
using namespace std;
void Print(int* arr, int size)
{
	int count = size / 2;
	int i=0, j=0;
	int originUp = 0;
	int originDown = size-1;
	int originLeft = 0;
	int originRight = size-1;
	while (count--)
	{
		for (j=originLeft; j < originRight; ++j)
			cout << arr[i*size+j] << " ";
		for (i=originUp; i< originDown; ++i)
			cout << arr[i*size + j] << " ";
		for (j=originRight; j>originUp; --j)
			cout << arr[i*size + j] << " ";
		for (i=originDown; i>originUp; --i)
			cout << arr[i*size + j] << " ";
		++originUp;
		--originDown;
		++originLeft ;
		--originRight;
	}
	if (size % 2)
	{
		cout << (size*size + 1) / 2;
	}
	cout << endl;
}
void Test1()
{
	int arr[4][4] = {
			{1,2,3,4},
			{5,6,7,8},
			{9,10,11,12},
			{13,14,15,16}
	};
	Print((int*)arr, 4);
	int arr1[3][3] = {
			{ 1, 2, 3},
			{ 4,5, 6},
			{ 7, 8, 9 }
	};
	Print((int*)arr1, 3);
}