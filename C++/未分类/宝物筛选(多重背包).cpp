#include <cstdio>
#include <algorithm>
using namespace std;
int dp[40000];
struct thing{
    int v,w;
}goods[101];
int main(){
    int n, W;
    scanf("%d %d", &n, &W);
    while(n --){
        int v, w, m;
        scanf("%d %d %d", &v, &w, &m);
        int cnt = 1;
        int s = m;
        for(int i = 1; i <= s; i *= 2){
            goods[cnt].v = i * v;
            goods[cnt++].w = i * w;
            s -= i;
        }
        if(s){
            goods[cnt].v = s * v;
            goods[cnt++].w = s * w;
        }
        for(int i = 1; i < cnt; i ++){
            for(int j = W; j >= 0; j --){ // 注意j的最小值
                if(j >= goods[i].w)
                    dp[j] = max(dp[j], dp[j-goods[i].w] + goods[i].v);
            }
        }
    }
    printf("%d", dp[W]);
    return 0;
}