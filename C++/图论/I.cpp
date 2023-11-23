#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
int n, k;
int f[1005];
int find(int x){
    if(x != f[x])
        f[x] = find(f[x]);
    return f[x];
}

struct edge{
    int from, to;
    double dis;
}e[1000005];

bool cmp(edge &a, edge &b){
    return a.dis < b.dis; 
}

struct node{
    int x, y;
}nodes[1005];

double road(node a, node b){
    return 1.0 * sqrt( 1.0*(a.x - b.x)*(a.x - b.x) + 1.0*(a.y - b.y)*(a.y - b.y) );
}

int main(){
    scanf("%d %d", &n, &k);
    int cnt = 0, count = 0;
    for(int i = 1; i <= n; i++){
        f[i] = i;
        scanf("%d %d", &nodes[i].x, &nodes[i].y);
    }
    for(int i = 1; i <= n; i ++){
        for(int j = i+1; j <= n; j ++){
            e[cnt].from = i, e[cnt].to = j;
            e[cnt++].dis = road(nodes[i], nodes[j]);
        }
    }
    sort(e, e+cnt, cmp);
    for(int i = 0; i < cnt; i ++){
        int x = e[i].from, y = e[i].to;
        if(find(x) != find(y)){
            f[find(x)] = find(y);
            count ++;
        }
        if(n - count + 1 == k){
            printf("%.2f\n",e[i].dis);
            break;
        }
    }
    return 0;
}
