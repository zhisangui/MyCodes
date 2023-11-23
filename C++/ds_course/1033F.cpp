#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode*next;
    ListNode(int vv, ListNode* nn = nullptr)
    {
        val = vv;
        next = nn;
    }
};

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int len, val;
        cin >> len;
        ListNode*head = new ListNode(-1), *curr = head;
        
        for(int i = 0; i < len; ++i)
        {
            cin >> val;
            ListNode*temp = new ListNode(val);
            curr->next = temp;
            curr = curr->next;
        }
        
        curr = head->next;

        while(curr)
        {
            int v = curr->val;
            ListNode* prev = curr, *temp = curr->next;
            while(temp)
            {
                if(temp->val == v)
                {
                    prev->next = temp->next;
                    delete temp;
                    temp = prev->next;
                    len--;
                }
                else
                {
                    prev = temp;
                    temp = temp->next;
                }
            }
            curr = curr->next;
        }
        curr = head->next;
        delete head;
        head = curr;
        curr = curr->next;
        cout << len << ": ";
        while(curr)
        {
            cout << head->val << ' ';
            delete head;
            head = curr;
            curr = curr->next;
        }
        cout << head->val << endl;
    }
    return 0;
}