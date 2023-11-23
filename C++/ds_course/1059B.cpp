#include<iostream>
#include<string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string masterString, patternString, replaceString;
        cin >> masterString >> patternString >> replaceString;
        int len_pattern = patternString.size();
        int *next = new int[len_pattern], i = 0, j = -1;
        next[0] = -1;
        while(i < len_pattern)
        {
            if(j == -1 || patternString[i] == patternString[j])
            {
                i++, j++;
                next[i] = j;
            }
            else
                j = next[j];
        }

        int len_masterString = masterString.size();
        i = 0, j = 0;
        while(i < len_masterString && j < len_pattern)
        {
            if(patternString[j] == masterString[i] || j == -1)
            {
                i++, j++;
            }
            else
                j = next[j];
        }
        if(j != len_pattern)
        {
            cout << masterString << endl
                << masterString << endl;
            continue;
        }
        int pos = i - j;
        cout << masterString << endl;
        for(int i = 0; i < len_pattern; ++i)
        {
            masterString.erase(masterString.begin()+pos);
        }
        int len_replace = replaceString.size();
        for(int i = 0; i < len_replace; ++i)
        {
            masterString.insert(masterString.begin()+pos, replaceString[i]);
        }
        cout << masterString << endl;
    }
    return 0;
}