#include <iostream>
#include <queue>
#include <iostream>
#include <string>
using namespace std;

int findIth(vector<vector<int>> vvi, int row, int val)
{
    for(int i = 0; i < row; ++i)
    {
        int col = vvi[i].size();
        for(int j = 0; j < col; ++j)
        {
            if(vvi[i][j] == val)
                return i;
        }
    }
    return -1;
}

int main()
{
    int t;
    cin >> t;
    vector<vector<int>> vvi(t + 5);  // 存放已有数据
    for(int i = 0; i < t; ++i)
    {
        int len;
        cin >> len;
        vector<int> temp(len);
        for(int j = 0; j < len; ++j)
        {
            cin >> temp[j];
        }
        vvi[i] = temp;
    }
    
    string op;
    int num;
    vector<queue<int>> ans(t+1);          // 存放新添数据
    vector<int> order;                    // 记录顺序,同时记忆化
    int isFirst = 1;
    while(cin >> op)
    {
        if(op == "STOP")
            break;
        if(op == "ENQUEUE")
        {
            cin >> num;
            int row = findIth(vvi, t, num);
            if(order.empty())                   // 第一个元素
            {
                ans[row].push(num);
                order.push_back(row);
            }
            else
            {
                int len = order.size();
                for(int i = 0; i < len; ++i)
                {
                    if(row == order[i])          // 遍历oeder（已出现过的队列行），若相同则添加，否则新建
                    {
                        ans[row].push(num);
                        break;
                    }
                    else if(i == len - 1)
                    {
                        ans[row].push(num);
                        order.push_back(row);
                    }
                }
            }
        }
        else if(op == "DEQUEUE")
        {
            int len = order.size();
            for(int i = 0; i < len; ++i)
            {
                if(!ans[order[i]].empty())
                {
                    if(isFirst)
                    {
                        cout << ans[order[i]].front();
                        isFirst = 0;
                    }
                    else
                    {
                        cout << ' ' << ans[order[i]].front();
                    }
                    ans[order[i]].pop();
                    if(ans[order[i]].size() == 0)
                    {
                        order.erase(order.begin()+i);
                    }
                    break;
                }
            }
        }
    }
    cout << endl;
    return 0;
}
