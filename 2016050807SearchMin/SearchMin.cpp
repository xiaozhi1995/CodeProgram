//把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 
//输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。 
//例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 
//思路：典型的缩小时间复杂度的方法，就是二分查找了。但是考虑到一种特殊的情况， 
//比如1 0 1 1 1是 0 1 1 1 1的旋转数组，此时进行二分，头尾中间都是1， 
//这怎么判断呢？顺序遍历数组 
//这样明显可以缩小时间复杂度。  
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
 		if (arr[left] == arr[mid] && arr[mid] == arr[right])//比如1 0 1 1 1是 0 1 1 1 1的旋转数组， 
 			//此时进行二分，头尾中间都是1，需要顺序遍历数组 
 			return SearchOrder(arr, size); 
 		if(arr[left]<arr[right])//此区域内有序 
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
 	return arr[right];//保证不会漏掉最后一个元素最小这种情况 
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
 		if (arr[left] == arr[mid] && arr[mid] == arr[right])//比如1 0 1 1 1是 0 1 1 1 1的旋转数组， 
 			//此时进行二分，头尾中间都是1，需要顺序遍历数组 
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

//把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 
//输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。 
//例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 
//思路：典型的缩小时间复杂度的方法，就是二分查找了。但是考虑到一种特殊的情况， 
//比如1 0 1 1 1是 0 1 1 1 1的旋转数组，此时进行二分，头尾中间都是1， 
#include<iostream> 
#include<assert.h> 
using namespace std;  
int binarySearch(int *arr, int front, int rear)//front为起点下标，rear为终点下标[] 
{ 
	if (front + 1 == rear || front == rear) 
		return arr[rear]<arr[front] ? arr[rear] : arr[front]; 
 	int index = (front + rear) / 2; 
 	if (arr[front] == arr[index] && arr[rear] == arr[index]){//此时两边中间都一样，考虑到特殊情况，我们两遍均遍历一次，进行最后的比较大小。 
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
