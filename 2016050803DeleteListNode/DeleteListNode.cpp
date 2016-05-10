//给定链表的头指针和一个结点指针，在O(1)时间删除该结点。链表结点的定义如下： 
//struct ListNode 
//{      int        m_nKey; 
//      ListNode*  m_pNext; 
//}; 
//函数的声明如下： 
//void DeleteNode(ListNode* pListHead, ListNode* pToBeDeleted); 
//如果删除节点为前面的n-1个节点，则时间复杂度为O(1)，只有删除节点为最后一个时， 
//时间复杂度才为O(n)，所以平均的时间复杂度为：（O(1) * (n-1) + O(n)）/n = O(1);仍然为O(1). 

#include<iostream>
using namespace std;
struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
	ListNode(const int x)
		:m_nValue(x)
		, m_pNext(NULL)
	{}
};
void PushBack(ListNode** pListHeadNode, const int x)
{
	if (*pListHeadNode == NULL)
	{
		*pListHeadNode = new ListNode(x);
	}
	else
	{
		ListNode* cur = *pListHeadNode;
		while (cur->m_pNext)
			cur = cur->m_pNext;
		cur->m_pNext = new ListNode(x);
	}
}
void DeleteList(ListNode** pListHeadNode)
{
	if (*pListHeadNode == NULL)
		return;

	ListNode* cur = *pListHeadNode;
	ListNode* del = NULL;
	while (cur)
	{
		del = cur;
		cur = cur->m_pNext;
		delete del;
	}
}
ListNode* Find(ListNode* pListHeadNode, const int key)
{
	if (pListHeadNode == NULL)
		return NULL;
	ListNode* cur = pListHeadNode;
	while (cur&&cur->m_nValue != key)
		cur = cur->m_pNext;
	return cur;
}
void DeleteNode(ListNode** pListHeadNode, ListNode* pToBeDelete)
{
	if (*pListHeadNode == NULL || pToBeDelete == NULL)
		return;
	ListNode* cur = *pListHeadNode;
	ListNode* del = NULL;
	if (NULL == pToBeDelete->m_pNext)//所要删除的为尾节点
	{
		if (cur == pToBeDelete)//只有一个节点且是要删除的，需重置头节点
		{
			delete pToBeDelete;
			*pListHeadNode = NULL;
		}
		else
		{
			while (cur->m_pNext != pToBeDelete)
			{
				cur = cur->m_pNext;
			}
			cur->m_pNext = NULL;
			delete pToBeDelete;
		}
	}
	else
	{
		if (pToBeDelete->m_pNext == NULL)
		{
			delete pToBeDelete;
			pToBeDelete = NULL;
		}
		else
		{
			del = pToBeDelete->m_pNext;
			pToBeDelete->m_nValue = del->m_nValue;
			pToBeDelete->m_pNext = del->m_pNext;
			delete del;
		}
	}
}
void Print(ListNode* pListHeadNode)
{
	ListNode* cur = pListHeadNode;
	while (cur)
	{
		cout << cur->m_nValue << " ";
		cur = cur->m_pNext;
	}
	cout << endl;
}
void Test1()
{
	ListNode*  pListHead = NULL;
	PushBack(&pListHead, 1);
	PushBack(&pListHead, 2);
	PushBack(&pListHead, 3);
	PushBack(&pListHead, 4);
	PushBack(&pListHead, 5);
	DeleteNode(&pListHead, Find(pListHead, 1));
	Print(pListHead);
	DeleteNode(&pListHead, Find(pListHead, 5));
	Print(pListHead);
	DeleteNode(&pListHead,Find(pListHead,3));
	Print(pListHead);
	DeleteNode(&pListHead,Find(pListHead,2));
	Print(pListHead);
	DeleteNode(&pListHead, Find(pListHead, 4));//测试删除最后一个节点
	Print(pListHead);
	DeleteList(&pListHead);
}