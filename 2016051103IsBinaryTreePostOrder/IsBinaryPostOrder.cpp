//二叉搜索树的后序遍历序列
//输入一个数组，判断该数组是不是某个二叉搜索树的后续遍历的结果
#include<iostream>
using namespace std;
bool IsBinaryTreePostOrder(int* arr, int size)
{
	if (arr == NULL || size <= 0)
		return false;
	int root = arr[size - 1];
	int i = 0;
	for (; i < size - 1; ++i)
	{
		if (arr[i] > root)
			break;
	}
	int j = i;
	for (; j < size - 1; ++j)
	{
		if (arr[j] < root)
			return false;
	}
	bool left = true;
	if (i > 0)
	{
		left = IsBinaryTreePostOrder(arr, i);
	}
	bool right = true;
	if (i < size - 1)
	{
		right = IsBinaryTreePostOrder(arr + i, size - 1 - i);
	}
	return left&&right;
}
void Test1()
{
	int arr[] = { 5, 7, 6, 9, 11, 10, 8 };
	cout << IsBinaryTreePostOrder(arr, sizeof(arr) / sizeof(arr[0])) << endl;
	int arr1[] = { 7, 4, 6, 5 };
	cout << IsBinaryTreePostOrder(arr1, sizeof(arr1) / sizeof(arr1[0])) << endl;
}