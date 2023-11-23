#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int KMP(string mainStr, string patternStr)
{
    int len1 = mainStr.size(), len2 = patternStr.size();
    int *next = new int[len2];
    int i = 1, j = 0;
    next[0] = 0;
    while(i < len2)
    {
        if(patternStr[i] == patternStr[j])
        {
            next[i++] = j++;
        }
        else if(j)
        {
            j = next[j-1];
        }
        else
        {
            next[i] = 0;
            i++;
        }
    }
    i = 0, j = 0;
    while(i < len1 && j < len2)
    {
        if(mainStr[i] == patternStr[j])
        {
            i++, j++;
        }
        else if(j)
        {
            j = next[j-1];
        }
        else
        {
            i++;
        }
    }
    delete[]next;
    return j == len2 ? j : -2;
}

int solve(string str)
{
    int ans = -1, len = str.size();
    for(auto left = str.begin(); left != str.end()-1; ++left)
    {
        for(auto right = left + 1; ; right++)
        {
            string temp(left,right);
            string ll(str.begin(),left);
            ans = max(ans, KMP(ll, temp));
            if(right == str.end())
                break;
            string rr(right, str.end());
            ans = max(ans, KMP(rr, temp));            
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
        int len = solve(str);
        cout << len << endl;
    }
    return 0;
}