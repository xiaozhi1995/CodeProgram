//��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת�� 
//����һ����������������һ����ת�������ת�������СԪ�ء� 
//��������{3,4,5,1,2}Ϊ{1,2,3,4,5}��һ����ת�����������СֵΪ1�� 
//˼·�����͵���Сʱ�临�Ӷȵķ��������Ƕ��ֲ����ˡ����ǿ��ǵ�һ������������ 
//����1 0 1 1 1�� 0 1 1 1 1����ת���飬��ʱ���ж��֣�ͷβ�м䶼��1�� 
//����ô�ж��أ�˳��������� 
//�������Կ�����Сʱ�临�Ӷȡ�  
#include<iostream> 
#include<assert.h> 
using namespace std; 
int SearchOrder(int arr[], int size) 
{ 
 	int ret = arr[0]; 
 	for (int i = 1; i < size; ++i) 
 	{ 
 		if (arr[i] < ret) 
 			ret = arr[i]; 
 	} 
 	return ret; 
} 
int SearchMinNum(int arr[],int size) 
{ 
 	int left=0; 
 	int right=size-1; 
 	int mid=0; 
 	assert(arr); 
 	while(left<=right) 
 	{ 
 		mid=left+((right-left)>>1); 
 		if (arr[left] == arr[mid] && arr[mid] == arr[right])//����1 0 1 1 1�� 0 1 1 1 1����ת���飬 
 			//��ʱ���ж��֣�ͷβ�м䶼��1����Ҫ˳��������� 
 			return SearchOrder(arr, size); 
 		if(arr[left]<arr[right])//������������ 
		{ 
 			return arr[left]; 
 		} 
 		else 
 		{ 
 			if(arr[right]>arr[mid]) 
 				right=right-1; 
 			else 
 				left=mid+1; 
 		} 
 	} 
 	return arr[right];//��֤����©�����һ��Ԫ����С������� 
} 
void Test1() 
{ 
 	int arr[]={4,3,2,1}; 
 	cout<<SearchMinNum(arr,4)<<endl; 
 	int arr1[] = { 1, 0, 1, 1, 1 }; 
 	cout << SearchMinNum(arr1, 5) << endl; 
 	int arr2[] = { 3, 4, 5, 1, 2 }; 
 	cout << SearchMinNum(arr2, 5) << endl; 
} 

#include<iostream> 
#include<assert.h> 
using namespace std; 
int SearchOrder(int arr[], int size) 
{ 
 	int ret = arr[0]; 
 	for (int i = 1; i < size; ++i) 
 	{ 
 		if (arr[i] < ret) 
 			ret = arr[i]; 
 	} 
 	return ret; 
} 
int SearchMinNum(int arr[],int size) 
{ 
 	int left=0; 
 	int right=size-1; 
 	int mid=0; 
 	assert(arr); 
 	while(arr[left]>=arr[right]) 
 	{ 
 		if (right - 1 == left) 
		{ 
 			mid = right; 
 			break; 
 		} 
 		mid=(left+right)/2; 
 		if (arr[left] == arr[mid] && arr[mid] == arr[right])//����1 0 1 1 1�� 0 1 1 1 1����ת���飬 
 			//��ʱ���ж��֣�ͷβ�м䶼��1����Ҫ˳��������� 
 			return SearchOrder(arr, size); 
 		if(arr[mid]>=arr[left]) 
 		{ 
 			left = mid; 
 		} 
 		else if (arr[mid] <= arr[right]) 
 		{ 
 			right = mid; 
 		} 
 	} 
 	return arr[mid]; 
} 
void Test1()
{ 
 	int arr[]={2,3,4,1}; 
 	cout<<SearchMinNum(arr,4)<<endl; 
 	int arr1[] = { 1, 0, 1, 1, 1 }; 
 	cout << SearchMinNum(arr1, 5) << endl; 
 	int arr2[] = { 3, 4, 5, 1, 2 }; 
 	cout << SearchMinNum(arr2, 5) << endl; 
} 

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
