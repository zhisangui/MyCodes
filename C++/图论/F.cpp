#include <cstdio>
#include <algorithm>
using namespace std;
int f[1005];
struct edge{
    int from, to, val;
}e[10005];
bool cmp(edge &a, edge &b){
    return a.val < b.val;
}
int find(int x){
    if(x != f[x])
        f[x] = find(f[x]);
    return f[x];
}
int main(){
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1; i <= m; i ++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        e[i].from = a, e[i].to = b, e[i].val = c;
    }
    if(k > n){
        printf("No Answer\n");
        return 0;
    }
    for(int i = 1; i <= n; i ++)
        f[i] = i;
    sort(e+1, e+1+m, cmp);
    int sum = 0, cnt = 0;
    for(int i = 1; i <= m; i ++){
        if(n - cnt == k)
            break;
        int a = e[i].from, b = e[i].to, c = e[i].val;
        if(find(a) != find(b)){
            f[find(a)] = find(b);
            cnt ++;
            sum += c;
        }
    }
    printf("%d\n", sum);
    return 0;
}