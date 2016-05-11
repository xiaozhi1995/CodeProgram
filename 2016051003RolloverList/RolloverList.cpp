//按给定数值逆序链表
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
	int Size()
	{
		if (_head == NULL)
			return 0;
		int size = 0;
		LinkNode<T>* cur = _head;
		while (cur)
		{
			++size;
			cur = cur->_next;
		}
		return size;
	}
public:
	void ReverseN(int size)
	{
		if (_head == NULL || size == 0 || size == 1)
			return;
		LinkNode<T>* newHead = NULL;
		LinkNode<T>* prevTail = NULL;
		LinkNode<T>* sectionHead = NULL;
		LinkNode<T>*  sectionTail = NULL;
		int sectionNum = 0;
		LinkNode<T>* cur = _head;
		while (cur)
		{
			int count = size;
			prevTail = sectionTail;
			sectionTail = cur;
			while (cur&&count--)
			{
				LinkNode<T>* tmp = cur;
				cur = cur->_next;
				tmp->_next = sectionHead;
				sectionHead = tmp;
			}
			++sectionNum;
			if (sectionNum == 1)
				newHead = sectionHead;
			else
				prevTail->_next = sectionHead;
		}
		sectionTail->_next = NULL;
		_head = newHead;
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
	l.Print();
	l.ReverseN(3);
	l.Print();
}
int main()
{
	Test1();
	system("pause");
	return 0;
}