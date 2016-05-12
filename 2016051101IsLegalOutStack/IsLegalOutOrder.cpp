//题目：给定一个入栈和一个出栈序列？请判断是否合法
//eg:入栈12345，出栈35124
//用一个辅助栈，如果栈为空，就push（入栈序列）
//比较栈顶元素和出栈序列当前值是否相等，若相等，出栈此元素，并将下次访问出栈序列位置后移；否则，继续入入栈序列里的元素。
//重复1，2步骤，直到入栈序列为空，且栈顶元素不等于出栈序列当前访问位置时即不合法。栈空，入栈序列空，出栈序列空为合法出栈。
#include<iostream>
#include<assert.h>
#include<stack>
using namespace std;
bool IsLegal(const char* inOrder, const char* outOrder)
{
    assert(inOrder&&outOrder);
    if (strlen(inOrder) != strlen(outOrder))
        return false;
    char* source = (char*)inOrder;
    char* dest = (char*)outOrder;
    stack<char> s;
    char ch;
    while (!s.empty() || *source != '\0')
    {
        while (!s.empty() && s.top()==*dest)
        {
            dest++;
            s.pop();
        }
        if (*source == '\0')
            break;
        s.push(*source++);
    }
    if (*dest == '\0')
        return true;
    else
        return false;
}
void Test1()
{
    cout << IsLegal("12345", "35124") << endl;
    cout << IsLegal("12345", "54321") << endl;
    cout << IsLegal("12345", "35421") << endl;
    cout << IsLegal("12345", "23451") << endl;
    cout << IsLegal("12345", "12345") << endl;
}