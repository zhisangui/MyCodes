#include <cstdio>
#include <algorithm>
using namespace std;
char sa[5005];
char sb[5005];
int dp[2][5005];
int main(){
    int n, ans = 0;
    scanf("%d", &n);
    getchar();
    scanf("%s", sa);
    for(int i = 0; i < n; i ++){
        sb[i] = sa[n-1-i];
    }
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++){
            if(sa[i] == sb[j])
                //dp[i+1][j+1] = dp[i][j]+1;
                dp[i&1][j+1] = dp[(i&1) ^ 1][j]+1;
            else    
                //dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
                dp[i&1][j+1] = max(dp[(i&1) ^ 1][j+1], dp[i&1][j]);
        }
    }
    printf("%d", n - dp[(n-1)&1][n]);
    return 0;
}