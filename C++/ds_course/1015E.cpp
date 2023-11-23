// 存在嵌套操作的题目，与递归的思想相似，可以使用递归解决

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>

using namespace std;
vector<string> vecstr;
string str;

int getNum(string str)
{
    return atoi(str.c_str());
}

bool isNum(string str)
{
    int num = getNum(str);
    return num >= 0 && num <= 99999;
}

string slove()
{
    cin >> str;

    if(str == "copy")
    {
        int n = getNum(slove());
        int x = getNum(slove());
        int l = getNum(slove());
        return vecstr[n].substr(x,l);
    }

    else if(str == "add")
    {
        string str1 = slove();
        string str2 = slove();
        if(isNum(str1) && isNum(str2))
        {
            return to_string(getNum(str1) + getNum(str2));
        }
        else
        {
            return str1 + str2;
        }
    }

    else if(str == "find")
    {
        string s = slove();
        int n = getNum(slove());
        if(vecstr[n].find(s) != -1)
            return to_string(vecstr[n].find(s));
        else
            return to_string(vecstr[n].size());
    }

    else if(str == "rfind")
    {
        string s = slove();
        int n = getNum(slove());
        if(vecstr[n].rfind(s) != -1)
            return to_string(vecstr[n].rfind(s));
        else
            return to_string(vecstr[n].size());        
    }

    else if(str == "insert")
    {
        string s = slove();
        int n = getNum(slove());
        int x = getNum(slove());
        vecstr[n].insert(x, s);
    }

    else if(str == "reset")
    {
        string s = slove();
        int n = getNum(slove());
        vecstr[n].clear();
        vecstr[n] = s;
    }

    else if(str == "print")
    {
        int n = getNum(slove());
        cout << vecstr[n] << endl;
    }

    else if(str == "printall")
    {
        int len = vecstr.size();
        for(int i = 1; i < len; ++i)
            cout << vecstr[i] << endl;
    }

    else 
    {
        return str;
    }
    
    return "";
}

int main()
{
    int num;
    cin >> num;
    vecstr.push_back("");
    for(int i = 1; i <= num; ++i)
    {
        string str;
        cin >> str;
        vecstr.push_back(str);
    }
    //slove();  单纯只有一个slove，只会运行一行指令，然后停止，不能多行指令。
    while(str != "over")
        slove();
    return 0;
}


