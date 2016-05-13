//��������(Quicksort)�Ƕ�ð�������һ�ָĽ���
//���Ļ���˼����:ͨ��һ������Ҫ��������ݷָ�ɶ����������֣�
//����һ���ֵ��������ݶ�������һ���ֵ��������ݶ�ҪС��Ȼ���ٰ�
//�˷����������������ݷֱ���п�����������������̿��Եݹ���У��Դ˴ﵽ�������ݱ���������С�
//�ڿӷ�
//����ȡ�з�����߿���Ч��
int GetMidNum(int* arr, int left, int right)
{
    int mid = left + ((right - left) >> 1);//ע�����ȼ�('+'���ڡ�>>'��Ч��
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
        while (begin < end&&arr[begin] <= tmp)//ע������������ͬ������Ӧ����֧��
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
 
//���Ƶ�һ�ַ��������ҵ���tmpС�ĺʹ�ģ�������������tmp��ֵ
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
        swap(arr[right], arr[index]);//�ص�
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
 
//��������
void Test1()
{
    int arr[] = { 2, 0, 4, 9, 3, 6, 8, 7, 1, 0 };
    Print(arr, 10);
    QuickSort(arr,0,9);
    Print(arr, 10);
 
}