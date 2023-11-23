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
    ~LinkList();
    void setValue();
    ListNode *LL_index(int i);   
    void LL_display();
    void swap(int l, int r);
};
LinkList::LinkList()
{
    head = new ListNode();
    len = 0;
}
LinkList::~LinkList()
{
    ListNode *p, *q;
    p = head;
    while(p != NULL)
    {
        q = p;
        p = p->next;
        delete q;
    }
    len = 0;
    head = NULL;
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
    LL_display();
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

ListNode* LinkList::LL_index(int i)
{
    ListNode* curr = head;
    for(int num = 0; num < i; ++num)
    {
        curr = curr->next;
    }
    return curr;
}

void LinkList::swap(int l, int r)
{
    if(l < 1 || l > len || r < 1 || r > len)
    {
        cout << "error" << endl;
        return;
    }
    ListNode* prel = LL_index(l-1), *p = LL_index(l), *np = LL_index(l+1);
    ListNode* prer = LL_index(r-1), *q = LL_index(r), *nq = LL_index(r+1);
    prel->next = q;
    q->next = np;
    prer->next = p;
    p->next = nq;
    LL_display();
}

int main()
{
    LinkList mylist;
    mylist.setValue();
    int l, r;

    cin >> l >> r;
    mylist.swap(l, r);
    cin >> l >> r;
    mylist.swap(l, r);
    return 0;
}