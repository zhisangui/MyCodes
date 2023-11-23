#include <iostream>
using namespace std;

struct ListNode
{
    ListNode* prev, *next;
    char val;
    ListNode(char v = '0', ListNode* p = nullptr, ListNode* q = nullptr)
    {
        val = v;
        prev = p;
        next = q;
    }
};

ListNode* initial(int n)
{
    ListNode* head = new ListNode(); 
    ListNode* prev = head, *curr;
    for(int i = 0; i < n; ++i)
    {
        char val;
        cin >> val;
        ListNode* curr = new ListNode(val, prev);
        prev->next = curr;
        prev = curr;
    }
    head->next->prev = nullptr;
    return head;
}



int main()
{
    int n, t;
    cin >> n;
    ListNode* head = initial(n);
    cin >> t;
    for(int i = 0; i < t; ++i)
    {
        char val;
        int index;
        cin >> index >> val;
        ListNode* curr = head->next, *prev = head;
        for(int j = 0; j < index; ++j)
        {
            prev = curr;
            curr = curr->next;
        }
        ListNode* temp = new ListNode(val, prev, curr);
        prev->next = temp;
        if(curr)
            curr->prev = temp;
        int flag = 1;   // 是否执行删除以及继续
        while(flag)
        {
            flag = 0;
            prev = head, temp = head->next, curr = head->next?head->next->next:nullptr;
            while(temp && curr)
            {
                if(prev->val == temp->val && temp->val == curr->val)
                {
                    flag = 1;
                    while(curr->next && temp->val == curr->next->val)
                    {
                        if(curr->next->next)
                        {
                            ListNode* rubbish = curr->next;
                            curr->next = rubbish->next;
                            rubbish->prev = curr;
                            delete rubbish;
                        }
                    }
                    break;
                }
                prev = prev->next;
                temp = temp->next;
                curr = curr->next;
            }
            if(flag)
            {
                if(!prev->prev && !curr->next)   //结束
                {
                    head->next = nullptr;
                }
                else if(!prev->prev && curr->next)  //无头有尾
                {
                    curr->next->prev = nullptr;
                    head->next = curr->next;
                }
                else if(prev->prev && !curr->next) //有头无尾
                {
                    prev->prev->next = nullptr;
                }
                else                                //有头有尾
                {
                    prev->prev->next = curr->next;
                    curr->next->prev = prev->prev;
                }
                delete prev, temp, curr;
            }
        }
        ListNode* newhead = head->next;
        int Print = 1;
        while(newhead)
        {
            Print = 0;
            cout << newhead->val;
            newhead = newhead->next;
        }
        if(Print)
            cout << '-';
        cout << endl;
    }
    return 0;
}
