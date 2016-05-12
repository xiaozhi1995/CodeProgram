#include<iostream>
#include<queue>
using namespace std;
struct BinaryTreeNode
{
	int data;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
	BinaryTreeNode(int x)
		:data(x)
		, left(NULL)
		, right(NULL)
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
			root->left = _CreateBinaryTree(arr, ++index, size);
			root->right = _CreateBinaryTree(arr, ++index, size);
		}
		return root;
	}
	void _Clear(BinaryTreeNode* root)
	{
		if (root == NULL)
			return;
		_Clear(root->left);
		_Clear(root->right);
		delete root;
	}
public:
	BinaryTree()
		:_root(NULL)
	{}
	~BinaryTree()
	{
		_Clear(_root);
	}
	BinaryTree(int *arr, int size)
	{
		int index = 0;
		_root = _CreateBinaryTree(arr, index, size);
	}
	void PrintTopToBottom()
	{
		if (_root == NULL)
			return;
		queue<BinaryTreeNode*> q;
		q.push(_root);
		BinaryTreeNode* cur = NULL;
		while (!q.empty())
		{
			cur = q.front();
			cout << cur->data << " ";
			q.pop();
			if (cur->left)
				q.push(cur->left);
			if (cur->right)
				q.push(cur->right);
		}
		cout << endl;
	}
};
void Test1()
{
	int arr[] = { 1, 2, 4, '#', '#', 5, '#', '#', 3, 6, '#', '#', 7 };
	BinaryTree bt1(arr, sizeof(arr) / sizeof(arr[0]));
	bt1.PrintTopToBottom();
}