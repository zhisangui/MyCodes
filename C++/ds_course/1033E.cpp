#include <iostream>
using namespace std;

struct ListNode
{

    int exp, coe;    // 指数，系数
    ListNode* next;
    ListNode(int e = -1, int c = -1, ListNode* nn = nullptr)
    {
        exp = e;
        coe = c;
        next = nn;
    }
};

void clear(ListNode* head)
{
    ListNode *p, *q;
    p = head;
    while(p)
    {
        q = p;
        p = p->next;
        delete q;
    }
}

void Print(ListNode* head)
{
    int isFirst = 1;
    while(head)
    {
        if(head->coe == 0)
        {
            head = head->next;
            continue;
        }           

        if(isFirst)
        {
            isFirst = 0;
        }
        else
        {
            cout << " + ";
        }

        if(head->coe < 0)
        {
            cout << '(' << head->coe << ')';
        }
        else
        {
            cout << head->coe;
        }

        if(head->exp == 0)
        {
            head = head->next;
            continue;
        }
        else if(head->exp < 0)
        {
            cout << "x^(" << head->exp << ')';
        }
        else
        {
            cout << "x^" << head->exp;
        }
        head = head->next;
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int num1, num2, exp, coe;
        ListNode* head1 = new ListNode, *curr1 = head1;
        ListNode* head2 = new ListNode, *curr2 = head2;
        ListNode* head3 = new ListNode, *curr3 = head3;

        cin >> num1;
        for(int i = 0; i < num1; ++i)
        {
            cin >> coe >> exp;
            ListNode* temp = new ListNode(exp, coe);
            curr1->next = temp;
            curr1 = curr1->next;
        }
        curr1 = head1->next;

        cin >> num2;
        for(int i = 0; i < num2; ++i)
        {
            cin >> coe >> exp;
            ListNode* temp = new ListNode(exp, coe);
            curr2->next = temp;
            curr2 = curr2->next;
        }
        curr2 = head2->next;

        while(curr1 && curr2)
        {
            ListNode* temp;
            if(curr1->exp == curr2->exp)
            {
                temp = new ListNode(curr1->exp, curr1->coe + curr2->coe);
                curr1 = curr1->next;
                curr2 = curr2->next;
            }
            else if(curr1->exp < curr2->exp)
            {
                temp = new ListNode(curr1->exp, curr1->coe);
                curr1 = curr1->next;
            }
            else
            {
                temp = new ListNode(curr2->exp, curr2->coe);
                curr2 = curr2->next;
            }
            curr3->next = temp;
            curr3 = curr3->next;
        }
        ListNode* rest = curr1?curr1:curr2;
        while(rest)
        {
            ListNode* temp = new ListNode(rest->exp, rest->coe);
            rest = rest->next;
            curr3->next = temp;
            curr3 = curr3->next;
        }
        
        Print(head1->next);
        Print(head2->next);
        Print(head3->next);
        
        clear(head1);
        clear(head2);
        clear(head3);
    }
}