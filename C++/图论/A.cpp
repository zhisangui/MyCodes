#include <bits/stdc++.h>
using namespace std;
int a[505];//入度数
int ans[505];//答案
int main(){
    int n, m;
    while(scanf("%d %d", &n, &m) != EOF){
        priority_queue <int, vector<int>, greater<int> > q;//拓扑队列
        memset(a, 0, sizeof(a));
        memset(ans, 0, sizeof(ans));
        vector<int> g[505];//邻接表 
        int p1, p2, cnt = 0;
        for(int i = 0; i < m; i ++){
            scanf("%d %d", &p1, &p2);
            a[p2]++;
            g[p1].push_back(p2);
        }
        for(int i = 1; i <= n; i ++)
            if(a[i] == 0)   
                q.push(i);
        while(!q.empty()){
            int qq = q.top();
            q.pop();
            ans[cnt++] = qq;
            for(int i = 0; i < g[qq].size(); i ++){
                a[g[qq][i]]--;
                if(a[g[qq][i]] == 0)
                    q.push(g[qq][i]);
            }
        }
        for(int i = 0; i < n - 1; i ++)
            printf("%d ", ans[i]);
        printf("%d", ans[n - 1]);
    }
    return 0;
}