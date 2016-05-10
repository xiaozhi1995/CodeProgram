//查找二叉树中两个节点的第一个公共父节点
#include<iostream>
#include<stack>
using namespace std;
struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
	BinaryTreeNode(const int& x)
		:m_nValue(x)
		, m_pLeft(NULL)
		, m_pRight(NULL)
	{}
};
class BinaryTree
{
protected:
	BinaryTreeNode* _root;
protected:
	BinaryTreeNode* _CreateTree(int* arr, int& index, const int size)
	{
		BinaryTreeNode* ret = NULL;
		if (index < size&&arr[index] != '#')
		{
			ret = new BinaryTreeNode(arr[index]);
			ret->m_pLeft = _CreateTree(arr, ++index, size);
			ret->m_pRight = _CreateTree(arr, ++index, size);
		}
		return ret;
	}
	void _Clear(BinaryTreeNode* root)
	{
		if (root == NULL)
			return;
		_Clear(root->m_pLeft);
		_Clear(root->m_pRight);
		delete root;
	}
	void _PreOrder(BinaryTreeNode* root)
	{
		if (root == NULL)
			return;
		cout << root->m_nValue << " ";
		_PreOrder(root->m_pLeft);
		_PreOrder(root->m_pRight);
	}
	bool _SearchFather(BinaryTreeNode* root, BinaryTreeNode* child, stack<BinaryTreeNode*>& ret)
	{
		bool flag = false;
		if (root == NULL)
			return false;
		if (root == child)
		{
			ret.push(root);
			return true;
		}
		ret.push(root);
		flag = _SearchFather(root->m_pLeft, child, ret);
		if (!flag)
		{
			flag = _SearchFather(root->m_pRight, child, ret);
		}
		if (!flag)
			ret.pop();
		return flag;
	}
	BinaryTreeNode* _CheckCommon(stack<BinaryTreeNode*> s1, stack<BinaryTreeNode*> s2)
	{
		int count1 = s1.size();
		int count2 = s2.size();
		int dif = 0;
		if (count1 > count2)
		{
			dif = count1 - count2;
			while (dif--)
				s1.pop();
		}
		else
		{
			dif = count2 - count1;
			while (dif--)
				s2.pop();
		}
		while (!s1.empty() && !s2.empty() && s1.top() != s2.top())
		{
			s1.pop();
			s2.pop();
		}
		if (!s1.empty())
			return s1.top();
		else
			return false;
	}
	BinaryTreeNode* _Find(BinaryTreeNode* root, const int& x)
	{
		if (NULL == root)
			return NULL;
		if (root->m_nValue == x)
			return root;
		if (NULL == _Find(root->m_pLeft, x))
		{
			return _Find(root->m_pRight, x);
		}
	}
public:
	BinaryTree(int *arr, const int size)
	{
		int index = 0;
		_root = _CreateTree(arr, index, size);
	}
	~BinaryTree()
	{
		_Clear(_root);
	}
	void PreOrder()
	{
		_PreOrder(_root);
		cout << endl;
	}
	BinaryTreeNode* Find(const int& x)
	{
		return _Find(_root, x);
	}
	BinaryTreeNode* SearchFirstComFather(BinaryTreeNode* childNode1, BinaryTreeNode* childNode2)
	{
		stack<BinaryTreeNode*> ret1;
		stack<BinaryTreeNode*> ret2;
		if (_SearchFather(_root, childNode1, ret1) && _SearchFather(_root, childNode2, ret2))
		{
			return _CheckCommon(ret1, ret2);
		}
	}
};
void Test1()
{
	int arr[] = { 1, 1, 2, '#', 7, '#', '#', 3, '#', '#', 4, 5, '#', '#', 6 };
	BinaryTree bt1(arr, sizeof(arr) / sizeof(arr[0]));
	bt1.PreOrder();
	cout << bt1.Find(1)->m_pLeft->m_nValue << bt1.Find(3)->m_nValue << endl;
	cout << bt1.SearchFirstComFather(bt1.Find(1), bt1.Find(3))->m_nValue << endl;
	cout << bt1.SearchFirstComFather(bt1.Find(7), bt1.Find(3))->m_nValue << endl;
	cout << bt1.SearchFirstComFather(bt1.Find(7), bt1.Find(2))->m_nValue << endl;
	cout << bt1.SearchFirstComFather(bt1.Find(3), bt1.Find(4))->m_nValue << endl;
}