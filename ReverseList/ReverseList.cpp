//��ת��������ڵ㶨�����£������ط�ת���ͷ�ڵ㡣
#include<stdio.h>
using namespace std;
struct ListNode
{
	int m_nkey;
	ListNode* m_pNext;
};
ListNode* Reverse(ListNode* head)
{
	if (head == NULL || head->m_pNext == NULL)
		return;
	ListNode* newHead = NULL;
	ListNode* cur = head;
	ListNode* temp = NULL;
	while (cur)
	{
		temp = cur;
		cur = cur->m_pNext;
		temp->m_pNext = newHead;
		newHead = temp;
	}
	return newHead;
}
