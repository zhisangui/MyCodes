#include <cstdio>
#include <algorithm>
using namespace std;

int a[100005];

int gcd(int u, int v){
    if(!v)
        return u;
    else
        return gcd(v, u % v);
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    int d = a[2] - a[1];
    if(d == 0){
        printf("%d", n);
        return 0;
    }
    int x;
    for(int i = 2; i <= n; i++){
        x = a[i] - a[i-1];  // 前后两个数的差
        if(x % d == 0 || d % x == 0)
            d = min(d, x);
        else if(x > d)
            d = gcd(x, d);
        else
            d = gcd(d, x);
    }
    printf("%d", (a[n] - a[1]) / d + 1);
    return 0;
}
