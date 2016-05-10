//输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍递增排序
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
ListNode* Merge(ListNode* head1, ListNode* head2)
{
	if (head1 == NULL)
		return head2;
	if (head2 == NULL)
		return head1;
	ListNode* ret = NULL;
	if (head1->m_nValue < head2->m_nValue)
	{
		ret = head1;
		ret->m_pNext = Merge(head1->m_pNext, head2);
	}
	else
	{
		ret = head2;
		ret->m_pNext = Merge(head1, head2->m_pNext);
	}
	return ret;
}
//非递归实现
//ListNode* Merge(ListNode* head1, ListNode* head2)
//{
//	if (head1 == NULL)
//		return head2;
//	if (head2 == NULL)
//		return head1;
//	ListNode* ret = NULL;
//	if (head1->m_nValue < head2->m_nValue)
//	{
//		ret = head1;
//		head1 = head1->m_pNext;
//	}
//	else
//	{
//		ret = head2;
//		head2 = head2->m_pNext;
//	}
//	ListNode* cur = ret;
//	while (head1&&head2)
//	{
//		if (head1->m_nValue < head2->m_nValue)
//		{
//			cur->m_pNext = head1;
//			head1 = head1->m_pNext;
//		}
//		else
//		{
//			cur->m_pNext = head2;
//			head2 = head2->m_pNext;
//		}
//		cur = cur->m_pNext;
//	}
//	if (head1 != NULL)
//		cur->m_pNext = head1;
//	else if (head2!=NULL)
//		cur->m_pNext = head2;
//	return ret;
//}
void Test1()
{
	ListNode* head1 = NULL;
	PushBack(&head1, 1);
	PushBack(&head1, 3);
	PushBack(&head1, 5);
	PushBack(&head1, 6);
	PushBack(&head1, 8);
	PushBack(&head1, 10);
	PushBack(&head1, 14);
	Print(head1);
	ListNode* head2 = NULL;
	PushBack(&head2, 2);
	PushBack(&head2, 3);
	PushBack(&head2, 5);
	PushBack(&head2, 8);
	PushBack(&head2, 10);
	PushBack(&head2, 16);
	PushBack(&head2, 20);
	Print(head2);

	ListNode* newHead = Merge(head1, head2);
	Print(newHead);
	DeleteList(&newHead);
}
int main()
{
	Test1();
	system("pause");
	return 0;
}