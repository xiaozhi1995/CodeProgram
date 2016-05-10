//题目：输入一个单向链表，输出该链表中倒数第k个结点。
//符合大多数人习惯，链表的倒数第1个结点为链表的最后一个节点。
//倒数第三个节点，1 2 3 4 5 6，应为4.
#include<iostream>
using namespace std;
template<class T>
struct LinkNode
{
	T _data;
	LinkNode* _next;
	LinkNode(const T& x)
		:_data(x)
		, _next(NULL)
	{}
};
template<class T>
class ListNode
{
	//为了安全性
private:
	ListNode(const ListNode& l)
	{}
	ListNode<T>& operator=(ListNode l)
	{}
protected:
	LinkNode<T>* _head;
public:
	ListNode()
		:_head(NULL)
	{}
	~ListNode()
	{
		if (_head == NULL)
			return;
		LinkNode<T>* cur = _head;
		LinkNode<T>* del = NULL;
		while (cur)
		{
			del = cur;
			cur = cur->_next;
			delete del;
		}
	}
	void PushBack(const T& x)
	{
		LinkNode<T>* tmp = new  LinkNode<T>(x);
		if (_head == NULL)
			_head = tmp;
		else
		{
			LinkNode<T>* cur = _head;
			while (cur->_next)
				cur = cur->_next;
			cur->_next = tmp;
		}
	}
	LinkNode<T>* SearchBackwardsLinkNode(int k)
	{
		if (_head == NULL)
			return NULL;
		int nodeCount = 0;
		LinkNode<T>* cur = _head;
		LinkNode<T>* ret = _head;
		while (cur)
		{
			while(cur&&nodeCount < k)
			{
				cur = cur->_next;
				++nodeCount;
			}
			if (nodeCount>k)
				return NULL;
			cur = cur->_next;
			ret = ret->_next;
		}
		return ret;
	}
	void Print()
	{
		LinkNode<T>* cur = _head;
		while (cur)
		{
			cout << cur->_data << " ";
			cur = cur->_next;
		}
		cout << endl;
	}
};
void Test1()
{
	ListNode<int> l;
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	l.PushBack(4);
	l.PushBack(5);
	l.PushBack(6);
	cout << l.SearchBackwardsLinkNode(3)->_data << endl;
}