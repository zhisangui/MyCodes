#include <cstdio>
#define MAX 5100
int sum[MAX];
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int temp;
    for(int i = 1; i <= n; i ++){
        scanf("%d", &temp);
        sum[i] = sum[i - 1] + temp;
    }
    double max = 0; 
    for(int i = m; i <= n; i ++){
        for(int j = 0; j <= n - i; j ++){
            if((sum[j+i] - sum[j]*1.0)/i > max)
                max = (sum[j+i] - sum[j]*1.0)/i;
        }
    }
    printf("%.8f", max);
    return 0;
}