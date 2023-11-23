#include <iostream>
#include <string>
using namespace std;

struct Stack
{
    char* ss;
    int top;
    Stack(int len)
    {
        ss = new char[len+1];
        top = 0;
    }
};

void push(Stack& s, char val)
{
    s.ss[s.top++] = val;
}

void pop(Stack& s)
{
    s.top--;
}

char top(Stack& s)
{
    return s.ss[s.top-1];
}

void clearStack(Stack& s)
{
    delete[]s.ss;
}

int main()
{ 
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
        int len = str.size();
        Stack s(len);
        for(int i = 0; i < len; ++i)
        {
            char c = str[i];
            push(s, c);
        }
        for(int i = 0; i < len; ++i)
        {
            char ans = top(s);
            cout << ans;
            pop(s);
        }
        clearStack(s);
        cout << endl;
    }
    return 0;
}