//二叉搜索树与双向链表，将二叉搜索树转换成排序的双向链表，
//要求不能创建新的节点，只能改变指向
#include<iostream>
#include<stack>
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
	void _Convert(BinaryTreeNode* root, BinaryTreeNode** head)//有可能改变head,加引用
	{
		if (root == NULL)
			return;

		BinaryTreeNode* cur = root;

		if (cur->left)
			_Convert(root->left, head);

		cur->left = *head;
		if (*head)
			(*head)->right = cur;

		*head = cur;
		if (cur->right)
			_Convert(cur->right, head);

	}
	//打印并销毁双向链表
private:
	static void PrintList(BinaryTreeNode* head)
	{
		if (head == NULL)
			return;
		BinaryTreeNode* cur = head;
		while (cur)
		{
			cout << cur->data << " ";
			if (cur->left)
				cout << "prev" << cur->left->data << " ";
			if (cur->right)
				cout << "next" << cur->right->data << endl;
			cur = cur->right;
		}
	}
	static void Destroy(BinaryTreeNode** head)
	{
		BinaryTreeNode* cur = *head;
		BinaryTreeNode* del = NULL;
		while (cur)
		{
			del = cur;
			cur = cur->right;
			delete del;
		}
		head = NULL;
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
			printf("%d ", cur->data);
			s.pop();
			if (cur->right)
				s.push(cur->right);
			if (cur->left)
				s.push(cur->left);
		}
	}
	BinaryTreeNode* TransformList()
	{
		if (_root == NULL)
			return NULL;//返回匿名对象
		//应按后序遍历顺序
		BinaryTreeNode* ret = NULL;
		_Convert(_root, &ret);

		while (ret != NULL&&ret->left != NULL)
			ret = ret->left;
		_root = NULL;
		PrintList(ret);
		Destroy(&ret);
	}
};
void Test1()
{
	int arr[] = { 10, 6, 4, '#', '#', 8, '#', '#', 14, 12, '#', '#', 16 };
	BinaryTree bt1(arr, sizeof(arr) / sizeof(arr[0]));
	bt1.PreOrder_Non();
	BinaryTreeNode* head = bt1.TransformList();
}