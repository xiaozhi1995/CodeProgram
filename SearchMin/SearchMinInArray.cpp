//��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת�� 
//����һ����������������һ����ת�������ת�������СԪ�ء� 
//��������{3,4,5,1,2}Ϊ{1,2,3,4,5}��һ����ת�����������СֵΪ1�� 
//˼·�����͵���Сʱ�临�Ӷȵķ��������Ƕ��ֲ����ˡ����ǿ��ǵ�һ������������ 
//����1 0 1 1 1�� 0 1 1 1 1����ת���飬��ʱ���ж��֣�ͷβ�м䶼��1�� 
#include<iostream> 
#include<assert.h> 
using namespace std;  
int binarySearch(int *arr, int front, int rear)//frontΪ����±꣬rearΪ�յ��±�[] 
{ 
	if (front + 1 == rear || front == rear) 
		return arr[rear]<arr[front] ? arr[rear] : arr[front]; 
 	int index = (front + rear) / 2; 
 	if (arr[front] == arr[index] && arr[rear] == arr[index]){//��ʱ�����м䶼һ�������ǵ�����������������������һ�Σ��������ıȽϴ�С�� 
 		int find1 = binarySearch(arr, front, index); 
 		int find2 = binarySearch(arr, index + 1, rear); 
 		return find1<find2 ? find1 : find2; 
 	} 
 	else if (arr[index] >= arr[front] && arr[index] > arr[rear]) 
 		return binarySearch(arr, index, rear); 
 	else 
 		return binarySearch(arr, front, index); 
} 
void Test1() 
{ 
 	int arr[] = { 2, 3, 4, 1 }; 
 	cout << binarySearch(arr, 0, 3) << endl; 
 	int arr1[] = { 1, 0, 1, 1, 1 }; 
 	cout << binarySearch(arr1, 0, 4) << endl; 
 	int arr2[] = { 3, 4, 0, 1, 2 }; 
 	cout << binarySearch(arr2, 0, 4) << endl; 
} 
