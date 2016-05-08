//���������ͷָ���һ�����ָ�룬��O(1)ʱ��ɾ���ý�㡣������Ķ������£� 
//struct ListNode 
//{      int        m_nKey; 
//      ListNode*  m_pNext; 
//}; 
//�������������£� 
//void DeleteNode(ListNode* pListHead, ListNode* pToBeDeleted); 
//���ɾ���ڵ�Ϊǰ���n-1���ڵ㣬��ʱ�临�Ӷ�ΪO(1)��ֻ��ɾ���ڵ�Ϊ���һ��ʱ�� 
//ʱ�临�ӶȲ�ΪO(n)������ƽ����ʱ�临�Ӷ�Ϊ����O(1) * (n-1) + O(n)��/n = O(1);��ȻΪO(1). 

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
	if (NULL == pToBeDelete->m_pNext)//��Ҫɾ����Ϊβ�ڵ�
	{
		if (cur == pToBeDelete)//ֻ��һ���ڵ�����Ҫɾ���ģ�������ͷ�ڵ�
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
	DeleteNode(&pListHead, Find(pListHead, 4));//����ɾ�����һ���ڵ�
	Print(pListHead);
	DeleteList(&pListHead);
}