#include<iostream>
using namespace std;
#define ok 0
#define error -1

// 链表结点定义
class ListNode
{
public:
    int data;
    ListNode *next;
    ListNode() {next = NULL;}
};
// 带头结点的单链表类定义
class LinkList
{
public:
    ListNode *head;
    int len;
    // 操作定义
    LinkList();
    ~LinkList();
    void setValue();
    ListNode *LL_index(int i);      // 返回第i个结点的指针，如果不存在返回NULL
    int LL_get(int i);              // 获取第i个元素的数据
    int LL_insert(int i, int item); // 把数值item插入第i个位置
    int LL_del(int i);              // 删除第i个结点
    void LL_display();              // 输出单链表的内容
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
    if(i < 0 || i > len)
        return nullptr;
    ListNode* curr = head;
    for(int num = 0; num < i; ++num)
    {
        curr = curr->next;
    }
    return curr;
}

int LinkList::LL_get(int i)
{
    ListNode* ith = LL_index(i);
    if(ith != nullptr && ith != head)
    {
        cout << ith->data << endl;
        return ith->data;
    }
    else
    {
        cout << "error" << endl;
        return error;
    }
} 

int LinkList::LL_insert(int i, int item)
{
    if(i <= 0 || i > len+1)
    {
        cout << "error" << endl;
        return error;
    }
    ListNode* preith = LL_index(i-1);
    if(preith)
    {
        ListNode* temp = new ListNode;
        temp->data = item;
        temp->next = preith->next;
        preith->next = temp;
        len++;
        LL_display();
        return ok;
    }
    return ok;
}

int LinkList::LL_del(int i)
{
    if(i < 1 || i > len)
    {
        cout << "error" << endl;
        return error;
    }
    ListNode* preith = LL_index(i-1);
    if(preith)
    {
        ListNode* temp = preith->next;
        preith->next = temp->next;
        delete temp;
        len--;
        LL_display();
        return ok;
    }
    return ok;
}

int main()
{
    LinkList mylist;
    mylist.setValue();
    int index, val;

    cin >> index >> val;
    mylist.LL_insert(index, val);
    cin >> index >> val;
    mylist.LL_insert(index, val);

    cin >> index;
    mylist.LL_del(index);
    cin >> index;
    mylist.LL_del(index);
    cin >> index;

    mylist.LL_get(index);
    cin >> index;
    mylist.LL_get(index);
    return 0;
}