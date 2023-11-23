#include <iostream>
#include <cstdio>
using namespace std;
const int VAlUE = 5;
const int coin = 101;
const int MONEY = 251;
int type[VAlUE] = {1, 5, 10, 25, 50};
int dp[MONEY][coin];              // 用coin个硬币组合成money金额的组合数
int ans[MONEY];                   // 组合成money金额的组合数
void solve(){
    dp[0][0] = 1;
    for(int i = 0; i < VAlUE; i ++){
        for(int j = type[i]; j < MONEY; j ++){
            for(int k = 1; k < coin; k ++){
                dp[j][k] += dp[j - type[i]][k - 1];
            }
        }
    }
}
int main(){
    int n;
    solve();
    for(int i = 0; i <= MONEY; i ++)
        for(int j = 0; j <= coin; j ++)
            ans[i] += dp[i][j];
    while(cin >> n){
        cout << ans[n] << endl;
    }
    return 0;
}