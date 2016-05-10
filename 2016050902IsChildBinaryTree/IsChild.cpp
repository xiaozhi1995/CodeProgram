#include<iostream>
#include<stack>
using namespace std;
struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
	BinaryTreeNode(const int x)
		:m_nValue(x)
		, m_pLeft(NULL)
		, m_pRight(NULL)
	{}
};
class BinaryTree
{
protected:
	BinaryTreeNode* _root;
	BinaryTreeNode* _CreateBinaryTree(int* arr, int& index, int size)
	{
		BinaryTreeNode* root = NULL;
		if (index < size&&arr[index] != '#')
		{
			root = new BinaryTreeNode(arr[index]);
			root->m_pLeft = _CreateBinaryTree(arr, ++index, size);
			root->m_pRight = _CreateBinaryTree(arr, ++index, size);
		}
		return root;
	}
	void _DeleteBinaryTree(BinaryTreeNode* root)
	{
		if (root == NULL)
			return;
		_DeleteBinaryTree(root->m_pLeft);
		_DeleteBinaryTree(root->m_pRight);
		delete root;
	}
	bool _HaveChild(BinaryTreeNode* root1, BinaryTreeNode* root2)
	{
		if (root2 == NULL)
			return true;
		if (root1 == NULL)
			return false;
		if (root1->m_nValue != root2->m_nValue)
			return false;
		return _HaveChild(root1->m_pLeft, root2->m_pLeft) && _HaveChild(root1->m_pRight, root2->m_pRight);
	}
	bool _IsChild(BinaryTreeNode* root1, BinaryTreeNode* root2)
	{
		bool ret = false;
		if (root1&&root2)
		{
			if (root1->m_nValue == root2->m_nValue)
			{
				ret = _HaveChild(root1, root2);
			}
			if (!ret)
			{
				ret = _IsChild(root1->m_pLeft, root2);
			}
			if (!ret)
			{
				ret = _IsChild(root1->m_pRight, root2);
			}
		}
		return ret;
	}
public:
	BinaryTree()
		:_root(NULL)
	{}
	~BinaryTree()
	{
		_DeleteBinaryTree(_root);
	}
	BinaryTree(int *arr, int size)
	{
		int index = 0;
		_root = _CreateBinaryTree(arr, index, size);
	}
	void PreOrder_Non()
	{
		if (_root == NULL)
			return;
		BinaryTreeNode* cur = _root;
		stack<BinaryTreeNode*> s;
		s.push(_root);
		while (!s.empty())
		{
			cur = s.top();
			printf("%d ", cur->m_nValue);
			s.pop();
			if (cur->m_pRight)
				s.push(cur->m_pRight);
			if (cur->m_pLeft)
				s.push(cur->m_pLeft);
		}
		cout << endl;
	}
	bool IsChild(BinaryTree& bt)
	{
		return _IsChild(_root, bt._root);
	}
};
void Test1()
{
	int arr[] = { 1, 2, 4, '#', '#', 5, '#', '#', 3, 6, '#', '#', 7 };
	BinaryTree bt1(arr, sizeof(arr) / sizeof(arr[0]));
	int arr1[] = { 2, 4, '#', '#', 5 };
	BinaryTree bt2(arr1, sizeof(arr1) / sizeof(arr1[0]));
	cout << bt1.IsChild(bt2) << endl;
}