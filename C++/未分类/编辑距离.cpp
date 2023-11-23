#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
const int m = 2005;
int dp[m][m];    //将字符串sa的 1到i 匹配到sb的 1到j 所需的最少操作数
char sa[m];
char sb[m];
int main(){
    scanf("%s %s", sa+1, sb+1);
    int a = strlen(sa+1), b = strlen(sb+1);
    for(int i = 0; i <= a; i ++)
        dp[i][0] = i;
    for(int j = 0; j <= b; j ++)
        dp[0][j] = j;
    for(int i = 1; i <= a; i++){
        for(int j = 1;j <= b; j ++){
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;
            if(sa[i] == sb[j])
                dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
            else 
                dp[i][j] = min(dp[i][j], dp[i-1][j-1]+1);
        }
    }
    printf("%d", dp[a][b]);
}