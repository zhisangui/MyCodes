#include <iostream>
#include <string>
#include <stack>
#include <map>
using namespace std;

int main()
{
    map<char, char> mp;
    mp[')'] = '(';
    mp['}'] = '{';
    mp[']'] = '[';
    mp['?'] = '?';
    int t;
    cin >> t;
    while(t--)
    {
        stack<char> s;
        s.push('?');
        string str;
        cin >> str;
        int len = str.size();
        for(int i = 0; i < len; ++i)
        {
            char c = str[i];
            if(c == '(' || c == '{' || c == '[')
                s.push(c);
            else if(c == ')' || c == '}' || c == ']')
            {
                if(s.top() == mp[c])
                {
                    s.pop();
                }
                else
                {
                    s.push(c);
                    break;
                }
            }
        }
        if(s.size() == 1)
            cout << "ok" << endl;
        else
            cout << "error" << endl;
    }
    return 0;
}