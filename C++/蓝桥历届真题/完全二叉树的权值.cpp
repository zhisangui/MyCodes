#include <cstdio>

long long a[1005];

int main(){
    long long n;
    long long cnt = 0;
    int ans;
    long long layer = 1, num = 1;
    long long x;
    scanf("%lld", &n);
    while(1){
        for(int j = 1; j <= num; j++){
            scanf("%lld", &x);
            cnt++;
			a[layer] += x;
            if(cnt >= n)
                break;
        }
        layer++;
        num *= 2;
        if(cnt >= n)
            break;
    }
    long long MAX = -99999999999999;
    for(int i = 1; i < layer; i++){
        if(MAX < a[i]){
            MAX = a[i];
            ans = i;
        }
    }
    printf("%d", ans);
}