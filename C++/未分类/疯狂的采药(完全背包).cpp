#include <cstdio>
#include <algorithm>
using namespace std;
int time[10005];
int value[10005];
long long dp[10000005];   //前i个草药用不超j的时间采集所得最大价值
int main(){
    int t, m;
    scanf("%d %d", &t, &m);
    for(int i = 1; i <= m; i ++)
        scanf("%d %d", &time[i], &value[i]);
    for(int i = 1; i <= m; i ++){
        for(int j = 0; j <= t; j ++){
            if(j >= time[i])
                dp[j] = 1ll * max(dp[j], dp[j - time[i]] + value[i]);
        }
    }
    printf("%lld\n", dp[t]);
    return 0;
}