#include <algorithm>
#include <cstdio>
using namespace std;
int a[105];
int dp[10005];
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i ++)
        scanf("%d", &a[i]);
    dp[0] = 1;
    for(int i = 1; i <= n; i ++){
        for(int j = m; j >= 0; j --){
            if(j > a[i])
                dp[j] += dp[j-a[i]];
            else if(j == a[i])
                dp[j] ++;
        }
    }
    printf("%d", dp[m]);
    return 0;
}