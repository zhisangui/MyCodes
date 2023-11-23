#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n;

long long c(int a, int b){
    long long res = 1;
    for(int i = a, j = 1; j <= b; i--, j++){
        res = res * i / j;
        if(res > n)
            return res;
    }
    return res; 
}

bool check(int k){//k为所在斜行，r为所在行
    int l = 2 * k, r = max(l, n);
    while(l < r){
        int mid = (l + r) >> 1;
        //long long res = ;
        if(c(mid, k) >= n)
            r = mid;
        else
            l = mid + 1;
    }
    if(c(r, k) == n){
        cout << 1ll * (r+1) * r / 2 + k + 1;
        return true;
    }
        //r = 5, k = 2 ans = 12
    return false;
}

int main(){
    cin >> n;
    if(n == 1){
        printf("1");
        return 0;
    }
    for(int i = 16; ; i--){
        if(check(i))
            break;
    }
    return 0;
}

