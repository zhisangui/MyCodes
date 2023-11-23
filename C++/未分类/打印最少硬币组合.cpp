#include <iostream>
#include <algorithm>
using namespace std;
const int VALUE = 5;
const int MONEY = 251;
int Min[MONEY];                              // 每个金额对应的最少的硬币数
int Min_path[MONEY];                         // 每个金额对应的最大硬币
int type[VALUE] = {1, 2, 10, 20, 50};        // 总共五种金额
void Print(int *a, int s){
    while(s){
        cout << a[s] << ' ';
        s -= a[s];
    }
}
void solve(){
    for(int i = 0; i < MONEY; i ++)
        Min[i] = 0x3f3f3f3f;   
    Min[0] = 0;
    for(int i = 0; i < VALUE; i ++){
        for(int j = type[i]; j < MONEY; j ++){
            if(Min[j] > Min[j - type[i]] + 1){
                Min[j] = Min[j - type[i]] + 1;
                Min_path[j] = type[i];
            }
        }
    }
}
int main(){
    int n;
    solve();
    while(cin >> n){
        cout << n << "所需的硬币是" << Min[n] << "个，分别为" << ':';
        Print(Min_path, n);
        cout << endl;
    }
    return 0;
}