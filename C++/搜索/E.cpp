#include <cstdio>
#define LL long long

LL ans, n;

void dfs(LL now, LL count){
    if(ans)
        return ;
    if(now > n && now % n == 0)
        ans = now;
    else if(count < 19){
        dfs(now * 10, count + 1);
        dfs(now * 10 + 1, count + 1);
    }
}

int main(){
    while(scanf("%lld", &n) != EOF && n){
        ans = 0;
        dfs(1ll * 1, 1ll * 0);
        printf("%lld\n", ans);
    }
    return 0;
}