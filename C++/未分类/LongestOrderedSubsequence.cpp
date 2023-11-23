#include <cstdio>
#include <algorithm>
using namespace std;
int a[1005];
int dp[1005]; // dp[i]表示为以i结尾的序列的最大子序列的长度
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    int res = 0;
    //dp[1] = 1;  则此句可以省略
    for(int i = 1; i <= n; i ++){
        dp[i] = 1;            // 该处若不加此句：a[1]若比较大，则后续比较时数量1，样例：3 3 1 2
        for(int j = 1; j < i; j ++){
            if(a[i] > a[j]){
                dp[i] = max(dp[j]+1, dp[i]);
            }
        }
        res = max(res, dp[i]);
    }
    printf("%d", res);
    return 0;
}