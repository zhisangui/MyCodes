#include <cstdio>
int a, b, mod;
int FastPow(int a, int n);
int main(){
    scanf("%d %d %d", &a, &b, &mod);
    printf("%d^%d mod %d=%d\n", a, b, mod, FastPow(a, b));
    return 0;
}
int FastPow(int a, int n){
    int res = 1, base = a;
    for(; n; n >>= 1){
        if(n & 1)
            res = res * 1LL * base % mod;
        base = base * 1LL * base % mod;
    }
    return res;
}