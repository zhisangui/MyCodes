#include <cstdio>
#include <algorithm>
using namespace std;
int tu[505][505];
int sum;
struct edge{
    int from, to, val;
}e[505*505];
int f[505];
bool cmp(edge &a, edge &b){
    return a.val < b.val;
}
int find(int x){
    if(x != f[x])
        f[x] = find(f[x]);
    return f[x];
}
int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    for(int i = 1; i <= b; i ++){
        for(int j = 1; j <= b; j ++){
            scanf("%d", &tu[i][j]);
        }
    }
    int cnt = 0;
    for(int i = 1; i <= b; i ++){
        for(int j = i+1; j <= b; j ++)
            if(tu[i][j])
                e[cnt].from = i, e[cnt].to = j, e[cnt++].val = min(a, tu[i][j]);     
    }
    sort(e, e+cnt, cmp);
    for(int i = 1; i <= b; i ++)
        f[i] = i;
    for(int i = 0; i < cnt; i++){
        int x = find(e[i].from), y = find(e[i].to);
        if(x != y){
            sum += e[i].val;
            f[x] = y;
        }
    }
    for(int i = 1; i <= b; i ++)
        if(i == f[i])
            sum += a;
    printf("%d", sum);
    return 0;
}