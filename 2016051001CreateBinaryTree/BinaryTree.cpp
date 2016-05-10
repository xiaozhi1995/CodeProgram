//根据树的前序和中序遍历构建树
#include<iostream>
using namespace std;
template<class T>
struct BinaryTreeNode
{
	T _data;
	BinaryTreeNode* _left;
	BinaryTreeNode* _right;
	BinaryTreeNode(const T& x)
		:_data(x)
		, _left(NULL)
		, _right(NULL)
	{}
};
template<class T>
class BinaryTree
{
protected:
	BinaryTreeNode<T>* _root;
protected:
	void _PreOrder(BinaryTreeNode<T>* root)
	{
		if (root != NULL)
		{
			cout << root->_data << " ";
			_PreOrder(root->_left);
			_PreOrder(root->_right);
		}
		return;
	}
	BinaryTreeNode<T>* _CreateBinary(char* preOrder, char* inOrder, int length)
	{
		BinaryTreeNode<T>* root = NULL;
		if (length == 0)
			return NULL;
		int tmp = *preOrder;
		int index = 0;
		while (index < length&&inOrder[index] != tmp)
			index++;
		if (index < length)
		{
			root = new BinaryTreeNode<T>(tmp - '0');
			root->_left = _CreateBinary(preOrder + 1, inOrder, index);
			root->_right = _CreateBinary(preOrder + index + 1, inOrder + index + 1, length - index - 1);
		}
		return root;
	}
	void _Clear(BinaryTreeNode<T>* root)
	{
		if (root)
		{
			_Clear(root->_left);
			_Clear(root->_right);
			delete root;
		}
	}
public:
	BinaryTree()
		:_root(NULL)
	{}
	~BinaryTree()
	{
		_Clear(_root);
		_root = NULL;
	}
	void  PreOrder()
	{
		_PreOrder(_root);
		cout << endl;
	}
	void CreateBinaryTree(char* preOrder, char* inOrder)
	{
		int length = strlen(preOrder);
		_root = _CreateBinary(preOrder, inOrder, length);
	}
};
void Test1()
{
	char* preOrder = "12473568";
	char* inOrder = "47215386";
	BinaryTree<int> bt;
	bt.CreateBinaryTree(preOrder, inOrder);
	bt.PreOrder();
}