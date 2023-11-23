// #include<iostream>
// #include<string>
// using namespace std;
// class myString
// {
// private:
//     string mainstr; // 串
//     int size;       // 串长度
//     void GetNext(string p, int *&next);
//     int KMPFind(string p, int pos, int *&next);
// public:
//     myString();
//     ~myString();
//     void SetVal(string sp);
//     int KMPFindSubstr(string p, int pos);
// };
// myString::myString()
// {
//     size = 0;
//     mainstr = "";
// }
// myString::~myString()
// {
//     size = 0;
//     mainstr = "";
// }
// void myString::SetVal(string sp)
// {
//     mainstr = " " + sp;
//     size = sp.length();
// }
// void myString::GetNext(string p, int *&next)
// {
//     int i = 1, j = 0, len = p.size()-1;
//     next[1] = 0;
//     while(i < len)
//     {
//         if(p[i] == p[j] || !j)
//         {
//             i++,j++;
//             next[i] = j;
//         }
//         else 
//         {
//             j = next[j];
//         }
//     }
// }
// int myString::KMPFind(string p, int pos, int *&next)
// {
//     int i = 1, j = 1, len = p.size()-1;
//     while(i <= size && j <= len)
//     {
//         if(mainstr[i] == p[j] || !j)
//         {
//             i++, j++;
//         }
//         else if(j)
//         {
//             j = next[j];
//         }
//     }
//     if(j == len+1)
//         return i - j + 1;
//     return 0;
// }
// int myString::KMPFindSubstr(string p, int pos)
// {
//     int i;
//     int L = p.length();
//     int *next = new int[L];
//     GetNext(p, next);
//     for(i = 1; i < L; i ++)
//         cout << next[i] - 1 << ' ';
//     cout << endl;
//     int v = -1;
//     v = KMPFind(p, pos, next);
//     delete []next;
//     return v;
// }

// int main()
// {
//     int t;
//     cin >> t;
//     while(t--)
//     {
//         myString str1;
//         string temp, str2;
//         cin >> temp >> str2;
//         str2 = " " + str2;
//         str1.SetVal(temp);
//         int ans = str1.KMPFindSubstr(str2,0);
//         cout << ans << endl;
//     }
//     return 0;
// }
#include <iostream>
#include <string>
using namespace std;
class myString
{
private:
    string mainstr; // 串
    int size;       // 串长度
    void GetNext(string p, int next[]);
    int KMPFind(string p, int next[]);

public:
    myString();
    ~myString();
    void SetVal(string sp);
    int KMPFindSubstr(string p);
};
myString::myString()
{
    size = 0;
    mainstr = "";
}
myString::~myString()
{
    size = 0;
    mainstr = "";
}
void myString::SetVal(string sp)
{
    mainstr = "";
    mainstr.assign(sp);
    size = mainstr.length();
}
int myString::KMPFindSubstr(string p)
{
    int i;
    int L = p.length();
    int *next = new int[L + 1];
    GetNext(p, next);
    for (i = 0; i <= L; i++)
        cout << next[i] << ' ';
    cout << endl;
    int *nextval = new int[L];
    nextval[0] = -1;
    for (int j = 1; j < L; j++)
    {
        if (p[next[j]] == p[j])
        {
            nextval[j] = nextval[next[j]];
        }
        else
        {
            nextval[j] = next[j];
        }
    }
    int v = -1;
    v = KMPFind(p, nextval);
    delete[] next;
    delete[] nextval;
    return v;
}
void myString::GetNext(string p, int next[])
{
    int i = 0;
    int j = -1;
    next[0] = -1;
    while (i < p.length())
    {
        if (j == -1 || p[i] == p[j])
        {
            ++i;
            ++j;
            next[i] = j;
        }
        else
        {
            j = next[j];
        }
    }
}
int myString::KMPFind(string p, int next[])
{
    int i = -1, j = -1;
    int l = p.length();
    while (i < size && j < l)
    {
        if (j == -1 || mainstr[i] == p[j])
        {
            ++i;
            ++j;
        }
        else
        {
            j = next[j];
        }
    }
    if (j > l - 1)
    {
        return i - l + 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        string p;
        cin >> p;
        myString ss;
        ss.SetVal(s);
        int item = ss.KMPFindSubstr(p);
        cout << item << endl;
    }
}