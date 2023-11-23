/*#include <cstdio>
#include <cmath>
const double PI = acos(-1);
double a[10005];
int main(){
    int t;
    scanf("%d", &t);
    while(t --){
        int n, f;
        scanf("%d %d", &n, &f);
        f ++;
        for(int i = 1; i <= n; i++){
            scanf("%lf", &a[i]);
            a[i] = PI * a[i] * a[i];
        }
        double l = 0, r = 1e19+10;
        for(int i = 1; i <= 100; i ++){
            double mid = (l + r) / 2;
            long long count = 0;
            for(int j = 1; j <= n; j ++){
                count += floor(a[j] / mid);
            }
            if(count >= f)
                l = mid;
            else
                r = mid ;
        }
        printf("%.4f\n", l);
    }
    return 0;
}*/
#include <cstdio>
#include <cmath>
const double PI = acos(-1);
int a[10005];
int main(){
    int t;
    scanf("%d", &t);
    while(t --){
        int n, f;
        scanf("%d %d", &n, &f);
        f ++;
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
        }
        double l = 0, r = 10005;
        for(int i = 1; i <= 100; i ++){
            double mid = (l + r) / 2;
            long long count = 0;
            for(int j = 1; j <= n; j ++){
                count += floor((PI * a[j] * a[j]) / (PI * mid * mid)); 
            }
            if(count >= f)
                l = mid;
            else
                r = mid ;
        }
        printf("%.4f\n", PI * l * l);
    }
    return 0;
}