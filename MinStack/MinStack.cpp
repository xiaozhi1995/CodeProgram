//����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ����СԪ��Min�������ڸ�ջ��
//Min,Push��Pop��ʱ�临�Ӷȶ���O��1��
#include<iostream>
#include<stack>
using namespace std;
template<class T>
class MinStack
{
protected:
	stack<T> _data;
	stack<T> _minData;
public:
	void Push(const T& x)
	{
		if (_data.empty())
		{
			_data.push(x);
			_minData.push(x);
		}
		else
		{
			_data.push(x);
			if (x < _minData.top())
			{
				_minData.push(x);
			}
			else
			{
				_minData.push(_minData.top());
			}
		}
	}
	void Pop()
	{
		assert(!_data.empty() && !_minData.empty());
		_data.pop();
		_minData.pop();
	}
	T& Min()
	{
		assert(!_data.empty() && !_minData.empty());
		return _minData.top();
	}
};