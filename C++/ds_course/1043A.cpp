#include <iostream>
using namespace std;

struct ListNode
{
    ListNode* prev, *next;
    int val;
    ListNode(int v = 0, ListNode* p = nullptr, ListNode* q = nullptr)
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
        int val;
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
    int n, m, val;
    cin >> n >> m;
    ListNode* head = initial(n);
    for(int i = 0; i < m; ++i)
    {
        cin >> val;
        ListNode* curr = head->next;
        while(curr)
        {
            if(val == curr->val)
            {
                int Print = 0;
                if(curr->prev)
                {
                    cout << curr->prev->val;
                    Print = 1;
                }
                if(curr->next)
                {
                    if(Print)
                        cout << ' ';
                    cout << curr->next->val;
                }
                cout << endl;
                break;
            }
            curr = curr->next;
        }
    }
    return 0;
}
