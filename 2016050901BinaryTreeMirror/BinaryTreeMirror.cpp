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
	BinaryTreeNode* _CreateMirror(BinaryTreeNode* root)
	{
		BinaryTreeNode* ret = NULL;
		if (root)
		{
			ret = new BinaryTreeNode(root->m_nValue);
			ret->m_pLeft = _CreateMirror(root->m_pRight);
			ret->m_pRight = _CreateMirror(root->m_pLeft);
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
	void CreateMirror(const BinaryTree& bt)
	{
		_root = _CreateMirror(bt._root);
	}
};
void Test1()
{
	int arr[] = { 1, 2, 4, '#', '#', 5, '#', '#', 3, 6, '#', '#', 7 };
	BinaryTree bt1(arr, sizeof(arr) / sizeof(arr[0]));
	BinaryTree bt2;
	bt2.CreateMirror(bt1);
	bt1.PreOrder_Non();
	bt2.PreOrder_Non();
}