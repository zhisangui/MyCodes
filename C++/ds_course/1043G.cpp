#include <iostream>
#include <stack>
#include <string>
#include <map>
using namespace std;

void prefix(string str)  // 栈顶>=新栈->出栈
{
    stack<string> ss;
    stack<char>sc;
    sc.push('?');
    map<char, int> pri;
    pri['+'] = pri['-'] = 1;
    pri['*'] = pri['/'] = 2;
    pri[')'] = 3;
    pri['('] = 0;
    pri['?'] = -1;
    int len = str.size();
    for(int i = len - 1; i >= 0; --i)
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            string num = "";
            num = str[i];
            int offset = -1;
            while(i + offset >= 0)
            {
                if(str[i + offset] >= '0' && str[i + offset] <= '9')
                {
                    num = str[i+offset] + num;
                    offset--;
                }
                else
                {
                    break;
                }
            }
            i = i + offset + 1;
            ss.push(num);
        }
        else if(str[i] == '(')
        {
            while(sc.top() != ')')
            {
                string temp;
                temp = sc.top();
                ss.push(temp);
                sc.pop();
            }
            sc.pop();
        }
        else
        {
            if(pri[sc.top()] <= pri[str[i]] || sc.top() == ')')
                sc.push(str[i]);
            else
            {
                while(pri[sc.top()] > pri[str[i]])
                {
                    string temp = "";
                    temp = sc.top();
                    ss.push(temp);
                    sc.pop();
                }
                sc.push(str[i]);
            }
        }
    }
    while(sc.size() != 1)
    {
        string temp = "";
        temp = sc.top();
        ss.push(temp);
        sc.pop();
    }
    int isFirst = 1;
    while(!ss.empty())
    {
        if(isFirst)
        {
            cout << ss.top();
            isFirst = 0;
        }
        else
        {
            cout << ' ' << ss.top();
        }
        ss.pop();
    }
    cout << endl;
}

void suffix(string str)
{
    stack<char> s;
    s.push('?');
    map<char, int> pri;
    pri['+'] = pri['-'] = 1;
    pri['*'] = pri['/'] = 2;
    pri['('] = 3;
    pri[')'] = 0;
    pri['?'] = -1;
    int len = str.size();
    int isFirst = 1;
    for(int i = 0; i < len; ++i)
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            if(isFirst)
            {
                isFirst = 0;
                cout << str[i];
            }
            else
            {
                cout << ' ' << str[i];
            }
            int offset = 1;
            while(offset + i < len)
            {
                if(str[offset + i] <= '9' && str[offset + i] >= '0')
                {
                    cout << str[i+offset];
                    offset++;
                }
                else
                {
                    break;
                }
            }
            i = i + offset - 1;
        }
        else if(str[i] == ')')
        {
            while(s.top() != '(')
            {
                if(isFirst)
                {
                    cout << s.top();
                    isFirst = 0;
                }
                else
                {
                    cout << ' ' << s.top();
                }
                s.pop();
            }
            s.pop();
        }
        else
        {
            if(pri[s.top()] < pri[str[i]] || s.top() == '(')
                s.push(str[i]);
            else
            {
                while(pri[s.top()] >= pri[str[i]])
                {
                    if(isFirst)
                    {
                        cout << s.top();
                        isFirst = 0;
                    }
                    else
                    {
                        cout << ' ' << s.top();
                    }
                    s.pop();
                }
                s.push(str[i]);
            }
        }
    }
    while(s.size() != 1)
    {
        if(isFirst)
        {
            cout << s.top();
            isFirst = 0;
        }
        else
        {
            cout << ' ' << s.top();
        }
        s.pop();
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
        prefix(str);
        suffix(str);
        if(t)
            cout << endl;
    }
    return 0;
}