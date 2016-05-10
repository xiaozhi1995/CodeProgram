#include<iostream>
using namespace std;
int Search(int* arr, int n, int x)
{
	int left = 0;
	int right = n - 1;
	int mid = 0;
	while (left <= right)
	{
		mid = left + ((right - left) >> 1);
		if (arr[mid] == x)
			return mid;
		else if (arr[mid] > x)
		{
			if (arr[left] > x)
				left = mid + 1;
			else
				right = mid - 1;
		}
		else
		{
			if (arr[right] < x)
				right = mid - 1;
			else
				left = mid + 1;
		}
	}
	return -1;
}
void Test1()
{
	int arr[10] = { 4, 5, 6, 7, 8, 9, 0, 1, 2, 3 };
	cout << Search(arr, 10, 4) << endl;
	cout << Search(arr, 10, 2) << endl;
	cout << Search(arr, 10, 10) << endl;
}
int main()
{
	Test1();
	system("pause");
	return 0;
}