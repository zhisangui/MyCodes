#include <cstdio>
#include <algorithm>
const int maxn = 105;
int f[maxn][maxn];
int a[maxn][maxn];
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= i; j ++)
            scanf("%d", &f[i][j]);
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= i; j ++){
            a[i][j] = std::max(a[i-1][j], a[i-1][j-1]) + f[i][j];
        }
    int mm = 0;
    for(int i = 1; i <= n; i ++)
        mm = std::max(mm, a[n][i]);
    printf("%d", mm);
    return 0;
}