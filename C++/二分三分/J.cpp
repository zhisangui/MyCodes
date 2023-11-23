#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define ll long long
ll a, b;
double f(ll x){
    return 1.0 * b * x + a * 1.0 / sqrt(x + 1.0);
}
int main(){
    scanf("%lld %lld", &a, &b);
    ll l = 0, r = 1e18+5;
    while (l + 3< r) //为什么这一步不能l<r
    {
        ll midl = l + (r - l) / 3;
        ll midr = r - (r - l) / 3;
        double ansl = f(midl);
        double ansr = f(midr);
        if(ansl >= ansr)
            l = midl;
        else
            r = midr;
    }
    double ans = 1e18+5;
    for(ll i = l; i <= r; i ++)
        if(f(i) < ans)
            ans = f(i);
    printf("%.10f", ans);
    return 0;
}