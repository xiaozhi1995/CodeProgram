//��Ŀ������һ����ջ��һ����ջ���У����ж��Ƿ�Ϸ�
//eg:��ջ12345����ջ35124
//��һ������ջ�����ջΪ�գ���push����ջ���У�
//�Ƚ�ջ��Ԫ�غͳ�ջ���е�ǰֵ�Ƿ���ȣ�����ȣ���ջ��Ԫ�أ������´η��ʳ�ջ����λ�ú��ƣ����򣬼�������ջ�������Ԫ�ء�
//�ظ�1��2���裬ֱ����ջ����Ϊ�գ���ջ��Ԫ�ز����ڳ�ջ���е�ǰ����λ��ʱ�����Ϸ���ջ�գ���ջ���пգ���ջ���п�Ϊ�Ϸ���ջ��
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