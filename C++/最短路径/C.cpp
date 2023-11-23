#include <iostream>
#include <queue>
#include <vector>
using namespace std;
//存储边
struct edge{
    int from, to, val;
    edge(int a, int b, int c)
        {from = a, to = b, val = c;}
};
vector<edge> e[2005];
//结点的id及到n的距离
struct node{
    int id, Dis;
    node(int a, int b)
        {id = a, Dis = b;}
    bool operator < (const node &a) const
    {return Dis > a.Dis;}
};
//dis[i]表示i到n点的距离
int dis[1005], done[1005];
int t,n;
const int MAX = 0x3f3f3f3f;

void dijkstra(){
    for(int i = 1; i <= n; i ++)
        dis[i] = MAX;
    dis[n] = 0; 
    priority_queue<node> q;
    q.push(node(n, dis[n]));
    while(q.size()){
        node u = q.top();
        q.pop();
        if(done[u.id])
            continue;
        done[u.id] = 1;
        for(int i = 0; i < e[u.id].size(); i ++){
            edge y = e[u.id][i];
            if(done[y.to])
                continue;
            if(y.val + u.Dis < dis[y.to]){
                dis[y.to] = y.val + u.Dis;
                q.push(node(y.to, dis[y.to]));
            }
        }
    }
}
int main(){
    cin >> t >> n;
    for(int i = 0; i < t; i ++){
        int a, b, c;
        cin >> a >> b >> c;
        e[a].push_back(edge(a,b,c));
        e[b].push_back(edge(b,a,c));
    }
    dijkstra();
    printf("%d\n", dis[1]);
}