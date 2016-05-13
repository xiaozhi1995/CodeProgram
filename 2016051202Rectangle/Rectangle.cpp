//经典矩阵问题是利用数字生成一个矩阵，而该矩阵刚好是一个正方形，该矩阵内的数字是有
//规律的排序而形成矩阵。比较常见有以下形式
//1.
//  1 2 9 10
//  4 3 8 11
//  5 6 7 12
//  16 15 14 13
//2.
//  1 2 6 7
//  3 5 8 13
//  4 9 12 14
//  10 11 15 16
//3.
//  1 2 3 4
//  12 13 14 5
//  11 16 15 6
//  10 9 8 7
//4.
//  7 6 5 16
//  8 1 4 15
//  9 2 3 14
//  10 11 12 13
#include<iostream>
using namespace std;
const int N = 5;//可修改
int a[N][N];
void Print(int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            printf("%-2d ",a[i][j]);
            cout << endl;
    }
    cout << endl;
}
void Rectangle1()
{
    int i = 0, j = 0;
    int lap = 1, m = 1, n;
    //cout<< "please input n行数";
    //cin >> n;
    n = 4;
    a[i][j] = m++;
    lap++;
    while (lap <= n)
    {
        if (lap % 2 == 0)
        {
            for (j++; i < lap; i++)
                a[i][j] = m++;
            i--;
            for (j--; j >= 0; j--)
                a[i][j] = m++;
            j++;
        }
        else
        {
            for (i++; j < lap; j++)
                a[i][j] = m++;
            j--;
            for (i--; i >= 0; i--)
                a[i][j] = m++;
            i++;
        }
        lap++;
    }
    Print(n);
}
void Rectangle2()
{
    int i = 0, j = 0;
    int s = 1, nNum = 1;//s标记升降方向，斜向上为升s=1,斜向下为降s=-1
    int n = 4;
    while (1)
    {
        if (s == 1)
        {
            a[i][j] = nNum;
            if (i - 1 < 0)
            {
                if (j + 1 == n)
                    i++;
                else
                    j++;
                s = -1;
            }
            else if (j + 1 == n)
            {
                i++;
                s = -1;
            }
            else
            {
                i--;
                j++;
            }
        }
        else
        {
            a[i][j] = nNum;
            if (j - 1 < 0)
            {
                if (j + 1 == n)
                    j++;
                else
                    i++;
                s = 1;
            }
            else if (i + 1 == n)
            {
                j++;
                s = 1;
            }
            else
            {
                i++;
                j--;
            }
        }
        nNum++;
        if (nNum > n*n)
            break;
    }
    Print(n);
}
void Rectangle3()
{
    int i = 0, j = 0;
    int n = 4;
    int x1=0, x2=n, y1=0, y2=n;//分别表示上下左右
    int m = 1, s = 1;//s=1表示升序，s=-1表示降序
    while (1)
    {
        if (s == 1)
        {
            for (j; j < y2; ++j)
                a[i][j] = m++;
            j--;
            i++;
            y2--;
            for (i; i < x2; ++i)
                a[i][j] = m++;
            i--;
            j--;
            x2--;
            s = -1;
        }
        else
        {
            for (j; j >=y1; --j)
                a[i][j] = m++;
            j++;
            i--;
            y1++;
            for (i; i>=x1+1; --i)
                a[i][j] = m++;
            i++;
            j++;
            x1++;
            s = 1;
        }
        if (m > n*n)
            break;
    }
    Print(n);
}
void Rectangle4()
{
    int i = 0, j = 0;
    int n = 4;
    int m = n*n;
    int x1 = 0, y1 = 0, x2 = n, y2 = n;
    int s = 1;
    if (n % 2 == 0)
    {
        j = n - 1;
        y2 = n - 1;
        s = 1;
    }
    else
    {
        i = n - 1;
        y1 = 1;
        s = -1;
    }
    while (1)
    {
        if (s == 1)
        {
            for (i; i < x2; ++i)
                a[i][j] = m--;
            i--;
            j--;
            x2--;
            for (j; j >= y1; --j)
                a[i][j] = m--;
            j++;
            i--;
            y1++;
            s = -1;
        }
        else
        {
            for (i; i >=x1; --i)
                a[i][j] = m--;
            i++;
            j++;
            x1++;
            for (j; j<y2; ++j)
                a[i][j] = m--;
            j--;
            i++;
            y2--;
            s = 1;
        }
        if (m < 1)
            break;
    }
    Print(n);
}
int main()
{
    Rectangle1();
    Rectangle2();
    Rectangle3();
    Rectangle4();
    system("pause");
    return 0;
}
