#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int MAX = 2147483647;
int n, m, s;
struct edge
{
    int from, to, val; 
    edge(int a, int b, int c){
        from = a; to = b, val = c;
    }
};
struct node
{
    int id, Dis;//id为结点， Dis为结点到起点的距离
    node(int a, int b)
    {id = a, Dis = b;}
    bool operator < (const node &a) const
    {return Dis > a.Dis;}
};
vector <edge> e[100005];
int dis[10005], done[10005];//dis记录所有结点到起点的距离
void dijkstra(){
    for(int i = 1; i <= n; i ++)
        dis[i] = MAX;
    dis[s] = 0;
    priority_queue<node> q;
    q.push(node(s, dis[s]));
    while(q.size()){
        node temp = q.top();
        q.pop();
        if(done[temp.id])
            continue;
        done[temp.id] = 1;
        for(int i = 0; i < e[temp.id].size(); i ++){
            edge y = e[temp.id][i];
            if(done[y.to])
                continue;
            if(y.val + dis[temp.id] < dis[y.to]){
                dis[y.to] = y.val + dis[temp.id];
                q.push(node(y.to, dis[y.to]));
            }
        }
    }
}
int main(){
    scanf("%d %d %d", &n, &m, &s);
    for(int i = 0; i < m; i ++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        e[a].push_back(edge(a, b, c));
    }
    dijkstra();
    for(int i = 1; i < n; i ++)
        printf("%d ", dis[i]);
    printf("%d", dis[n]);
    return 0;
}