#include <iostream>
#include <string>
#include <vector>
using namespace std;

string getSubstr(string str, int left, int right)
{
    string ans = "";
    for(int i = left; i <= right; ++i)
        ans += str[i];
    return ans;
}

string matched_Prefix_Postfix(string str)
{
    int len = str.size();
    vector<string> prefix(len), postfix(len);
    for(int i = 0; i < len - 1; ++i)
    {
        prefix[i] = getSubstr(str, 0 ,i);
        postfix[i] = getSubstr(str, len - 1 - i, len - 1);
    }
    string ans = "empty";
    for(int i = len-2; i >= 0; --i)
    {
        for(int j = 0; j < len - 1; ++j)
        {
            if(prefix[i] == postfix[j])
            {
                ans = prefix[i];
                return ans;
            }
        }
        
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
        string ans = matched_Prefix_Postfix(str);
        cout << ans << endl;
    }
    return 0;
}