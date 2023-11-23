#include <cstdio>
#include <cstring>
const int mod = 10000;
struct matrix{
    long long m[10][10];
    matrix(){
        memset(m, 0, sizeof(m));
    }
}a, b;

matrix Ma(matrix x, matrix y){
    matrix ret;
    for(int i = 0; i < 2; i ++)
        for(int j = 0; j < 2; j ++)
            for(int k = 0; k < 2; k ++)
                ret.m[i][j] = ( 1ll * ret.m[i][j] + (x.m[i][k] % mod) * (y.m[k][j] % mod) ) % mod; 
    return ret;
}

matrix Powfast(matrix a, int n){
    matrix ret;
    if(n == 0)
        return ret;
    for(int i = 0; i < 2; i ++) 
        ret.m[i][i] = 1;
    for(; n; n >>= 1){
        if(n & 1)
            ret = Ma(ret, a);
        a = Ma(a, a);
    }
    return ret;
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF && n != -1){
        a.m[0][0] = 1;
        a.m[0][1] = 1;
        a.m[1][0] = 1;
        a.m[1][1] = 0;
        b = Powfast(a, n);
        printf("%d\n", b.m[0][1]);
    }
    return 0;
}