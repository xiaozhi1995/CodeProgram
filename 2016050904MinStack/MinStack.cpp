//定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素Min函数，在该栈中
//Min,Push，Pop的时间复杂度都是O（1）
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