#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> edges[100005];
int ans[100005];
int dfs(int x, int now){
    if(ans[x])
        return ans[x];
    else
        ans[x] = now;
    for(int i = 0; i < edges[x].size(); i ++){
        dfs(edges[x][i], now);
    }
    return ans[x];
}
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i ++){
        int x, y;
        scanf("%d %d", &x, &y);
        edges[y].push_back(x);
    }
    for(int i = n; i; i --)
        dfs(i, i);
    for(int i = 1; i < n; i ++)
        printf("%d ", ans[i]);
    printf("%d\n", ans[n]);
    return 0;
}