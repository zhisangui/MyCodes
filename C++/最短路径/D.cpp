#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;

int t, n, m, cnt;
int dis[1005], done[1005];   // 结点到起点的距离， 结点是否被访问

struct edge  //存储边
{
    int from, to, weight;
    edge(int a, int b, int c)
    {from = a, to = b, weight = c;}
};
vector<edge> e[1005];

struct node
{
    int id, Weight; //id为结点，weight为当前结点到结点1的道路最大限重
    node(int a, int b)
    {id = a, Weight = b;}
    bool operator < (const node &a) const
    { return Weight < a.Weight;}  
};

void dijkstra(int s)
{
    dis[s] = INF;
    priority_queue<node> q;
    q.push(node(s, dis[s]));
    while(q.size())
    {
        node u = q.top();
        //if(u.id == n) break;
        q.pop();
        if(done[u.id]) continue;    // 若当前结点已经被找过，则跳过当前循环
        done[u.id] = 1;         
        for(int i = 0; i < e[u.id].size(); i++)  // 遍历结点的所连边
        {
            edge y = e[u.id][i];
            dis[y.to] = max(dis[y.to], min(y.weight, dis[u.id])); 
            q.push(node(y.to, dis[y.to]));
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> t;
    //scanf("%d", &t);
    while (t--)
    {
        cin >> n >> m;
        //scanf("%d %d", &n, &m);
        //memset(dis, -1, sizeof(dis));
        for(int i = 1; i <= n; i++)         // 初始化
            dis[i] = done[i] = 0;
        for(int i = 0; i <= n; i++)
            e[i].clear();
        //memset(done, 0, sizeof(done));
        for(int i = 0; i < m; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            //scanf("%d %d %d", &a, &b, &c);
            e[a].push_back(edge(a, b, c));
            e[b].push_back(edge(b, a, c));
        }
        dijkstra(1);
        printf("Scenario #%d:\n%d\n\n", ++cnt, dis[n]);
    }
    return 0;
}

