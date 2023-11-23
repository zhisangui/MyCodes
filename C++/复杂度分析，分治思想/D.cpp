#include <cstdio>
#include <algorithm>
const int MAX = 5e5+5;
int a[MAX];
int sum[MAX];
int main(){
    int n;
    int min = 0;
    int max = -0x3f3f3f3f;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &a[i]);
        sum[i] = a[i] + sum[i - 1];
        max = std::max(max, sum[i] - min);
        min = std::min(min, sum[i]);
    }
    printf("%d\n", max);
    return 0;
}