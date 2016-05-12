//复杂链表的复制，什么是复杂链表？
//一个链表的每个节点，有一个指向next指针指向下一个节点，还有一个random指针指向这
//个链表中的一个随机节点或者NULL，现在要求实现复制这个链表，返回复制后的新链表。
//复杂链表的定义：
//typedef struct ComplexNode
//{
//	DataType	 _data;				// 数据
//	struct ComplexNode* _next;		// 指向下一个节点的指针
//	struct ComplexNode* _random;	// 指向随机节点
//}ComplexNode;
#include<iostream>
using namespace std;
#define  DataType int
typedef struct ComplexNode
{
	DataType  _data;//存储数据
	struct  ComplexNode  *_next;//下一个节点地址
	struct  ComplexNode  *_random;//随机指向的节点地址
}ComplexNode, *pComplexNode;
pComplexNode  BuyNode(DataType x)
{
	pComplexNode tmp = NULL;
	tmp = (pComplexNode)malloc(sizeof(ComplexNode));
	tmp->_data = x;
	tmp->_next = NULL;
	tmp->_random = NULL;
	return tmp;
}
void Pushback(pComplexNode& pHead, DataType x)
{
	pComplexNode  cur = pHead, pre = NULL;
	if (pHead == NULL)
	{
		pHead = BuyNode(x);
		pHead->_random = NULL;
	}
	else
	{
		while (cur->_next)
		{
			pre = cur;
			cur = cur->_next;
		}
		cur->_next = BuyNode(x);
		cur->_random = pre;
		cur->_next->_random = cur;
	}
}
void  Printf(pComplexNode pHead)
{
	while (pHead)
	{
		printf("%d", pHead->_data);
		if (pHead->_random)
		{
			printf(" random:%d  ->", pHead->_random->_data);
		}
		else
			printf(" random:NULL  ->");
		pHead = pHead->_next;
	}
	printf("NULL\n");
}
void CopyDoubleNext(pComplexNode head)
{
	pComplexNode cur = head;
	pComplexNode tmp = NULL;
	while (cur)
	{
		tmp = BuyNode(cur->_data);
		if (cur->_next)
			tmp->_next = cur->_next;
		cur->_next = tmp;
		cur = cur->_next->_next;
	}
}
void CopyDoubleRandom(pComplexNode head)
{
	pComplexNode cur = head;
	while (cur)
	{
		if (cur->_random)
			cur->_next->_random = cur->_random->_next;
		cur = cur->_next->_next;
	}
}
pComplexNode ApartList(pComplexNode head)
{
	pComplexNode dest = head->_next;
	pComplexNode cur = head;
	pComplexNode destCur = dest;
	cur->_next = destCur->_next;
	cur = cur->_next;
	while (cur)
	{
		destCur->_next = cur->_next;
		destCur = destCur->_next;

		cur->_next = destCur->_next;
		cur = cur->_next;
	}
	destCur->_next = NULL;
	return dest;
}
void CopyComplex(pComplexNode*  src, pComplexNode*  dest)
{
	if (src == NULL)
		return;
	CopyDoubleNext(*src);
	CopyDoubleRandom(*src);
	*dest = ApartList(*src);
}
void  Destory(pComplexNode&  pHead)
{
	pComplexNode del = NULL;
	if (pHead == NULL)
		return;
	while (pHead)
	{
		del = pHead;
		pHead = pHead->_next;
		free(del);
	}
}
void Test1()
{
	pComplexNode pHead = NULL, target = NULL;
	Pushback(pHead, 1);
	Pushback(pHead, 2);
	Pushback(pHead, 3);
	Pushback(pHead, 4);
	Pushback(pHead, 5);
	Pushback(pHead, 6);
	Printf(pHead);

	CopyComplex(&pHead, &target);
	Printf(target);
	Destory(pHead);
	Destory(target);
}