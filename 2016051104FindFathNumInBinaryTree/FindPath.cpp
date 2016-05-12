//二叉树中和为某一值的路径
//输入一颗二叉树和一个整数，打印出二叉树中节点值的和为整数的所有路径，从根节点到
//开始往叶点所经过的路径
#include<iostream>
#include<vector>
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
	void _ToPath(BinaryTreeNode* root, const int num, vector<BinaryTreeNode*>& v, int& currentNum)
	{
		currentNum += root->data;
		v.push_back(root);
		bool isLeaf = root->left == NULL&&root->right == NULL;
		if (currentNum == num&&isLeaf)
		{
			cout << "a path is: ";
			vector<BinaryTreeNode*>::iterator  iter = v.begin();
			for (; iter < v.end(); ++iter)
				cout << (*iter)->data << " ";
			cout << endl;
		}
		if (root->left)
			_ToPath(root->left, num, v, currentNum);
		if (root->right)
			_ToPath(root->right, num, v, currentNum);

		currentNum -= root->data;
		v.pop_back();
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
	void ToSumPath(int num)
	{
		if (_root == NULL)
			return;
		int currentNum = 0;
		vector<BinaryTreeNode*>  v;
		_ToPath(_root, num, v, currentNum);
	}
};
void Test1()
{
	int arr[] = { 10, 5, 4, '#', '#', 7, '#', '#', 12 };
	BinaryTree bt1(arr, sizeof(arr) / sizeof(arr[0]));
	bt1.ToSumPath(22);
}