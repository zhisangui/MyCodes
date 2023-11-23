/*#include <cstdio>
//#include <vector> 
#include <algorithm>*/
#include <bits/stdc++.h>
#define LL long long
using namespace std;

int a[200005];

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n+m+1; i++){
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + m + 2, greater<int>() );
    LL sum = 0;
    if(m == 0)
        for(int i = 1; i <= n+m+1; i++)
            sum += 1ll * a[i];
    else{
        sum = 1ll * -1 * a[n+m+1];
        for(int i = 1; i <= n+m; i++)
            sum += 1ll * abs(a[i]);
    }
    printf("%lld", sum);
    return 0;
}