#include <bits/stdc++.h>
using namespace std;

int a[105];
int cnt;
char dp[105][100005];//状态表示f[i][j]：表示前i个砝码中选，称出的重量为j的状态，为1表示可以称出，为0则不能称出。
/*f[i - 1][j]：i - 1个砝码能称出的，i个也能称出
f[i - 1][j - a[i]]：加上当前的砝码
f[i - 1][j + a[i]]：减去当前的砝码*/
int n, x, m;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x;
        a[i] = x;
        m += x;
    }
    dp[0][0] = 1;
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j <= m; ++j){
            if(a[i]==j)
                dp[i][j] = 1;
            else
                dp[i][j] = (dp[i-1][j] || dp[i-1][abs(j - a[i])] || dp[i-1][j + a[i]]);
        }
    }
    for(int i = 1; i <= m; ++i)
        if(dp[n][i])
            cnt++;
    cout << cnt;
}   