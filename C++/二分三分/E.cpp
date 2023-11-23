#include<cstdio>
#include<math.h>
double wood[10005];
int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i ++){
        scanf("%lf", &wood[i]);
    }
    double l = 0, r = 100005;
    for(int i = 1; i <= 100; i ++){
        double mid = (l + r) / 2;
        long long cnt = 0;
        for(int j = 1; j <= n; j ++){
            cnt += floor(wood[j] / mid);
        }
        if(cnt >= k)
            l = mid;
        else
            r = mid;
    }
    printf("%.2f", floor(l*100)/100);
    return 0;
}