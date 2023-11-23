#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main()
{
    string a, b, c;
    int array_a[28], array_b[28], array_c[28];
    while(cin >> a >> b >> c)
    {
        int len = a.size();
        memset(array_a,0,sizeof(array_a));
        memset(array_b,0,sizeof(array_b));
        memset(array_c,0,sizeof(array_c));
        for(int i = 0; i < len; ++i)
        {
            array_a[a[i]-'A']++;
            array_b[b[i]-'A']++;
            array_c[c[i]-'A']++;
        }
        int success = 1;
        int v1 = 0, v2 = 0;
        for(int i = 0; i < 26; ++i)
        {
            if(array_a[i] + array_b[i] < array_c[i])
            {
                success = 0;
                break;
            }
            v1 += max(0, array_c[i]-array_a[i]);
            v2 += max(0, array_c[i]-array_b[i]);
        }
        if(v1 > len/2 || v2 > len/2)
            success = 0;
        if(success)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
