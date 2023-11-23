#include <iostream>
using namespace std;

struct ListNode
{
    ListNode* next;
    int val;
    ListNode(int v = 0, ListNode* p = nullptr)
    {
        val = v;
        next = p;
    }
};

ListNode* initial(int n)
{
    ListNode* head = new ListNode(); 
    ListNode* prev = head, *curr;
    for(int i = 0; i < n; ++i)
    {
        curr = new ListNode(i + 1);
        prev->next = curr;
        prev = curr;
    }
    curr->next = head->next;
    return head;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, k, s;
        cin >> n >> k >> s;
        ListNode* head = initial(n);
        ListNode* prev = head, *curr = head->next;
        int len = s - 1;
        while(len--)
        {
            prev = prev->next;
            curr = curr->next;
        }
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < k-1; ++j)
            {
                prev = prev->next;
                curr = curr->next;
            }
            cout << curr->val << ' ';
            prev->next = curr->next;
            ListNode* temp = curr;
            if(curr == head->next)
                head->next = curr->next;
            curr = curr->next;
            delete temp;
        }
        cout << endl;
    }
    return 0;
}