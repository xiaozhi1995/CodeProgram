//看看两个链表相交到底是怎么回事吧，有这样的的几个事实：（假设链表中不存在环）
//　　（1）一旦两个链表相交，那么两个链表中的节点一定有相同地址。
//　　（2）一旦两个链表相交，那么两个链表从相交节点开始到尾节点一定都是相同的节点
#include<iostream>
#include<assert.h>
using namespace std;
template<class T>
struct LinkNode
{
        T _data;
        LinkNode* _next;
        LinkNode(const T& x)
        :_data(x)
        ,_next(NULL)
        {}
};
template<class T>
class ListNode
{
//为了安全性
private:
        ListNode(const ListNode& l)
        {}
        ListNode<T>& operator=(ListNode l)
        {}
public:
        //程序限制
        LinkNode<T>* _head;
public:
        ListNode()
        :_head(NULL)
        {}
        ~ListNode()
        {
                while(_head)
                {
                        PopBack();
                }
        }
        void PushBack(const T& x)
        {
                LinkNode<T>* tmp=new  LinkNode<T>(x);
                if(_head==NULL)
                        _head=tmp;
                else
                {
                        LinkNode<T>* cur=_head;
                        while(cur->_next)
                                cur=cur->_next;
                        cur->_next=tmp;
                }
        }  
        void PopBack()
        {
                if(_head==NULL)
                        return;
                if(_head->_next==NULL)
                {
                        delete _head;
                        _head=NULL;
                }
                else
                {
                        LinkNode<T>* cur=_head;
                        while(cur->_next&&cur->_next->_next)
                        {
                             cur=cur->_next;
                        }
                        LinkNode<T>* del=cur->_next;
                        cur->_next=NULL;
                        delete del;
                }
        }
        LinkNode<T>* Search(const T& x)
        {
                if(_head==NULL)
                        return  NULL;
                LinkNode<T>*  cur=_head;
                while(cur->_data!=x)
                        cur=cur->_next;
                return cur;
        } 
};
template<class T>
LinkNode<T>* CheckLink(const ListNode<T>& l1,const ListNode<T>& l2)
{
        assert(l1._head&&l2._head);
        int lengthCount1=0;
        int lengthCount2=0;
        LinkNode<T>* head1=l1._head;
        LinkNode<T>* head2=l2._head;
        while(head1)
        {
                ++lengthCount1;
                head1=head1->_next;
        }
        while(head2)
        {
                ++lengthCount2;
                head2=head2->_next; 
        }
        int subLength=0;
        head1=l1._head;
        head2=l2._head;
        if(lengthCount1>lengthCount2)
        {
                subLength=lengthCount1-lengthCount2;
                while(subLength--)
                        head1=head1->_next;
        }
        else
        {
                subLength=lengthCount1-lengthCount2;
                while(subLength--)
                        head2=head2->_next;
        }
        while(head1&&head1!=head2)
       {
           head1=head1->_next;
           head2=head2->_next;
       }
       return head1;
}
 
void Test1()
{ 
        ListNode<int> l1;
        l1.PushBack(1);
        l1.PushBack(2);
        l1.PushBack(3);
        l1.PushBack(4);
        l1.PushBack(5);
        ListNode<int> l2;
        l2.PushBack(1);
        l2.PushBack(2);
        (l2.Search(2))->_next=l1.Search(4);
        cout<<CheckLink(l1,l2)->_data<<endl;//可判断返回值是否为空得到是否相交
}
int main()
{
        Test1();
//      cout<<"Hello world"<<endl;
        return 1;
}