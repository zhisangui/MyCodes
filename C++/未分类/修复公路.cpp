#include <cstdio>
#include <algorithm>
using namespace std;
struct node{
    int x, y, t;
}roads[100005];
int f[100005];
bool cmp(const node &a, const node &b){
    return a.t < b.t;
}
int find(int a){
    if(a == f[a])
        return a;
    else
        return f[a] = find(f[a]);
}
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i ++){
        scanf("%d %d %d", &roads[i].x, &roads[i].y, &roads[i].t);
    }
    int count = 0;
    sort(roads + 1, roads + 1 + m, cmp);
    for(int i = 1; i <= n; i ++)
        f[i] = i;
    for(int i = 1; i <= m; i ++){
        if(find(roads[i].x) != find(roads[i].y)){
            f[find(roads[i].x)] = find(roads[i].y);
            count ++;
        }
        if(count == n-1){
            printf("%d", roads[i].t);
            break;
        }
    }
    if(count != n-1)
        printf("-1");
    return 0;
}