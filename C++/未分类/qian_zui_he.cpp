#include <stdlib.h>
#include <stdio.h>
#include <cstring>
/*#define element_size int(1e6)
int a[element_size];
int sum[element_size];
void init(int n);
int qsum(int l, int r);
int main(){
    int n, x, y;
    scanf("%d", &n);
    init(n);
    scanf("%d %d", &x, &y);
    printf("%lld", qsum(x, y));
    return 0;
}
void init(int n){
    sum[0] = 0;
    for(int i = 1; i <= n; i ++){
        scanf("%d", &a[i]);
        sum[i] = sum[i - 1] + a[i];
    }
}
int qsum(int l, int r){
    return sum[r] - sum[l-1];
}*/
int sum[200][200];
int a[200][200];
void init(int n, int m);
int qsum(int x, int y, int u, int v);
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    init(n, m);
    int x, y, u, v;
    scanf("%d %d %d %d", &x, &y, &u, &v);
    printf("%d", qsum(x, y, u, v));
    return 0;
}
void init(int n, int m){
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            scanf("%d", &a[i][j]);
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
        }
    }
}
int qsum(int x, int y, int u, int v){
    return sum[u][v] - (sum[x-1][v] + sum[u][y-1] - sum[x-1][y-1]);
}