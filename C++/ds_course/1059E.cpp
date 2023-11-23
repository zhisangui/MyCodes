#include <iostream>
#include <string>
using namespace std;

void solve(string str)
{
    int len = str.size();
    int *next = new int[len+1];
    next[0] = -1;
    int i = 0, j = -1;
    while(i < len)
    {
        if(str[i] == str[j] || j == -1)
        {
            next[++i] = ++j;
        } 
        else
        {
            j = next[j];
        }
    }
    if(len % (len-next[len]) == 0)
    {
        if(next[len] == 0)
            cout << len << endl;
        else
            cout << 0 << endl;
    }
    else
        cout << len-next[len]-(next[len]%(len-next[len])) << endl;
    delete[]next;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        solve(str);
    }
    return 0;
}