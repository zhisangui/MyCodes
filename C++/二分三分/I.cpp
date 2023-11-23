#include <cstdio>
double a[20];
int main(){
    double l, r;
    int n;
    scanf("%d %lf %lf", &n, &l, &r);
    for(int i = 0; i < n + 1; i ++)
        scanf("%lf", &a[i]);
    for(int k = 1; k <= 100; k ++){
        double midl = l + (r-l) / 3;
        double midr = r - (r-l) / 3;

        double sum = a[n];
        for(int i = 0; i < n; i ++){
            double t = 1;
            for(int j = 0; j < n - i ; j ++)
                t *= midl;
            sum += a[i] * t;
        }

        double res = a[n];
        for(int i = 0; i < n; i ++){
            double t = 1;
            for(int j = 0; j < n - i ; j ++)
                t *= midr;
            res += a[i] * t;
        }
        if(sum <= res)
            l = midl;
        else
            r = midr;
    }
    printf("%.5f\n", l);
    return 0;
}