#include <cstdio>
#include <algorithm>
using namespace std;
struct road{
    int from, to, val;
}roads[100005];
bool cmp(road &a, road &b){
    return a.val < b.val;
}
int f[305];
int find(int a){
    if(a != f[a])
        f[a] = find(f[a]);
        return f[a];
}
int main(){
    int n, m;
    int Max = 0, cnt = 0;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i ++){
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);
        roads[i].from = a, roads[i].to = b, roads[i].val = c;
    }
    sort(roads + 1, roads + 1 + m, cmp);
    for(int i = 1; i <= n; i ++)
        f[i] = i;
    for(int i = 1; i <= m; i ++){
        int a = roads[i].from, b = roads[i].to;
        if(find(a) != find(b)){
            f[find(a)] = find(b);
            Max = max(Max, roads[i].val);
            cnt ++;
        }
        if(cnt == n - 1)
            break;
    }
    printf("%d %d", cnt, Max);
    return 0;
}