//用堆栈实现迷宫问题，二维数组表示迷宫：1表示墙壁，0表示可以走的路，只能横着走或竖着走
//不能斜着走，要求编程实现找到从左上角到右下角的路线
//深度优先：有解就退出搜索（不一定是最优解）
#include<iostream>
#include<stdio.h>
using namespace std;
#define ROW 5
#define COL 5
typedef struct point
{
    int _row;
    int _col;
}Point;
Point stack[512];
int top= 0;
void Push(Point& p)
{
    stack[top++] = p;
}
const Point& Pop()
{
    return stack[--top];
}
int IsEmpty()
{
    return top==0;
}
int maze[ROW][COL] = {
        { 0, 0, 0, 0, 0 },
        { 0, 1, 1, 1, 0 },
        { 0, 1, 1, 0, 0 },
        { 0, 1, 1, 0, 1 },
        { 0, 0, 0, 0, 0 },
};
void PrintMaze()
{
    for (int i = 0; i < ROW; ++i)
    {
        for (int j = 0; j < COL; ++j)
        {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
Point Prev[ROW][COL] = {
        { { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 } },
        { { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 } },
        { { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 } },
        { { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 } },
        { { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 } },
};
void Visit(int row, int col,Point& p)
{
    Point tmp = { row, col};
    maze[row][col] = 2;
    Prev[row][col] = p;
    Push(tmp);
}
void Test1()
{
    Point p = { 0, 0};
    maze[p._row][p._col] = 2;
    Push(p);
 
    while (!IsEmpty())
    {
        p = Pop();
        if (p._row == ROW - 1 && p._col == COL - 1)
            break;
 
        //up
        if (p._row - 1 >= 0 && maze[p._row - 1][p._col] == 0)
            Visit(p._row - 1, p._col,p);
        //down
        if (p._row + 1 < ROW&&maze[p._row + 1][p._col] == 0)
            Visit(p._row + 1, p._col,p);
        //left
        if (p._col - 1 >= 0 && maze[p._row][p._col - 1] == 0)
            Visit(p._row, p._col - 1,p);
        //right
        if (p._col + 1 < COL&&maze[p._row][p._col + 1] == 0)
            Visit(p._row, p._col + 1,p);
    }
    if (p._row == ROW - 1 && p._col == COL - 1)
    {
        printf("(%d,%d)\n", p._row, p._col);
        while ((Prev[p._row][p._col])._row != -1)
        {
            p = Prev[p._row][p._col];
            printf("(%d,%d)\n", p._row, p._col);
        }
    }
    else
        cout << "no path!\n";
}
//广度求得最优路径，找到后停止搜索
#include<iostream>
using namespace std;
#define ROW 5
#define COL 5
typedef struct point
{
    int _row;
    int _col;
    int _prev;
}Point;
Point queue[512];
int head = 0;
int tail = 0;
void Enqueue(Point& p)
{
    queue[tail++] = p;
}
const Point& Dequeue()
{
    return queue[head++];
}
int IsEmpty()
{
    return head == tail;
}
int maze[ROW][COL] = {
        { 0, 0, 0, 0, 0 },
        { 0, 1, 1, 1, 0 },
        { 0, 1, 1, 0, 0 },
        { 0, 1, 1, 0, 1 },
        { 0, 0, 0, 0, 0 },
};
void PrintMaze()
{
    for (int i = 0; i < ROW; ++i)
    {
        for (int j = 0; j < COL; ++j)
        {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void Visit(int row, int col)
{
    Point tmp = { row, col, head - 1 };
    maze[row][col] = 2;
    Enqueue(tmp);
}
void Test1()
{
    Point p = { 0, 0, -1 };
    maze[p._row][p._col] = 2;
    Enqueue(p);
 
    while (!IsEmpty())
    {
        p = Dequeue();
        if (p._row == ROW - 1 && p._col == COL - 1)
            break;
          
        //up
        if (p._row - 1 >= 0 && maze[p._row - 1][p._col] == 0)
            Visit(p._row - 1, p._col);
        //down
        if (p._row + 1 < ROW&&maze[p._row + 1][p._col] == 0)
            Visit(p._row + 1, p._col);
        //left
        if (p._col - 1 >= 0 && maze[p._row][p._col - 1] == 0)
            Visit(p._row, p._col - 1);
        //right
        if (p._col + 1 < COL&&maze[p._row][p._col + 1] == 0)
            Visit(p._row, p._col + 1);
    }
    if (p._row == ROW - 1 && p._col == COL - 1)
    {
        printf("(%d,%d)\n", p._row, p._col);
        while (p._prev != -1)
        {
            p = queue[p._prev];
            printf("(%d,%d)\n", p._row, p._col);
        }
    }
    else
        cout << "no path!\n";
}