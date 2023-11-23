#include <iostream>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;
    ListNode(){}
};
class LinkList
{
public:
    ListNode *head;
    int len;
    LinkList();
    void setValue();
    void LL_display();
};
LinkList::LinkList()
{
    head = new ListNode();
    len = 0;
}
void LinkList::setValue()
{
    cin >> len;
    ListNode* curr = head;
    for(int i = 1; i <= len; ++i)
    {
        ListNode* temp = new ListNode;
        cin >> temp->data;
        curr->next = temp;
        curr = curr->next;
    }
    curr->next = nullptr;
}
void LinkList::LL_display()
{
    ListNode *p;
    p = head->next;
    while(p)
    {
        cout << p->data << ' ';
        p = p->next;
    }
    cout << endl;
}

int LL_merge(ListNode *La, ListNode *Lb)
{
    LinkList ans;
    ListNode*curr = ans.head;
    ListNode*oria = La, *orib = Lb;
    while(La && Lb)
    {
        if(La->data < Lb->data)
        {
            curr->next = La;
            La = La->next;
        }
        else
        {
            curr->next = Lb;
            Lb = Lb->next;
        }
        curr = curr->next;
    }
    curr->next = La?La:Lb;
    ans.LL_display();
    ans.head = nullptr;
    La = oria, Lb = orib;
    return 0;
}

int main()
{
    LinkList l1, l2;
    l1.setValue();
    l2.setValue();
    LL_merge(l1.head->next, l2.head->next);
    return 0;
}