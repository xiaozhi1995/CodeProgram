//快速排序(Quicksort)是对冒泡排序的一种改进。
//它的基本思想是:通过一趟排序将要排序的数据分割成独立的两部分，
//其中一部分的所有数据都比另外一部分的所有数据都要小，然后再按
//此方法对这两部分数据分别进行快速排序，整个排序过程可以递归进行，以此达到整个数据变成有序序列。
//挖坑法
//三数取中法，提高快排效率
int GetMidNum(int* arr, int left, int right)
{
    int mid = left + ((right - left) >> 1);//注意优先级('+'大于‘>>'和效率
    if (arr[left] < arr[right])
    {
        if (arr[right] < arr[mid])
            return right;
        else if (arr[left] > arr[mid])
            return left;
        else
            return mid;
    }
    else//arr[left] >=arr[right]
    {
        if (arr[right] > arr[mid])
            return right;
        else if (arr[left] < arr[mid])
            return left;
        else
            return mid;
    }
}
void QuickSort(int* arr, int left, int right)
{
    assert(arr);
    if (left >= right)
        return;
    int tmpIndex =GetMidNum(arr, left, right);
    if (tmpIndex != right)
        swap(arr[tmpIndex], arr[right]);
    int tmp = arr[right];
    int begin = left;
    int end = right;
    while (begin < end)
    {
        while (begin < end&&arr[begin] <= tmp)//注意若有两个相同的数，应予以支持
            ++begin;
        if (begin < end)
            arr[end--] = arr[begin];
        while (begin < end&&arr[end] >= tmp)
            --end;
        if (begin < end)
            arr[begin++] = arr[end];
    }
    arr[begin] = tmp;
    QuickSort(arr, left, begin-1);
    QuickSort(arr, begin+1,right);
 
}
 
//类似第一种方法，先找到比tmp小的和大的，交换，最后放置tmp的值
int Quick_Sort(int *arr, int left, int right)
{
    assert(arr);
    if (left >= right)
        return right;
    int tmp = arr[right];
    int index = right;
    --right;
    while (left < right)
    {
        while (left < right&&arr[left] <= tmp)
            left++;
        while (left < right&&arr[right] >=tmp)
            right--;
        if (left < right)
            swap(arr[left], arr[right]);
    }
    if (arr[right] >= tmp)
        swap(arr[right], arr[index]);//重点
    return right;
}
void QuickSort(int* arr,int left,int right)
{
    assert(arr);
    if (left < right)
    {
        int mid = Quick_Sort(arr, left, right);
        QuickSort(arr, left, mid-1);
        QuickSort(arr, mid+1, right);
    }
     
}
 
//测试用例
void Test1()
{
    int arr[] = { 2, 0, 4, 9, 3, 6, 8, 7, 1, 0 };
    Print(arr, 10);
    QuickSort(arr,0,9);
    Print(arr, 10);
 
}