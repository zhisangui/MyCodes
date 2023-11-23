#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 1005
int sum[MAX][MAX];
int a[MAX][MAX];
int m, n, x, y;
void init();
int get_max(); 
int main(){
    int t;
    scanf("%d" , &t);
    while (t--){
        memset(a, 0, sizeof(a));
        memset(sum, 0, sizeof(sum));
        scanf("%d %d %d %d", &m, &n, &x, &y);
        init();
        printf("%d\n", get_max());
    }
    return 0;
}
void init(){
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j ++){
            scanf("%d", &a[i][j]);
            sum[i][j] = sum[i-1][j] + sum[i][j-1] -sum[i-1][j-1] + a[i][j];
        }
    }
}
int get_max(){
    int max = 0;
    for(int i = 1; i <= m+1-x; i ++){
        for(int j = 1; j <= n+1-y; j ++){
            int x1 = i, y1 = j, x2 = i+x-1, y2 = j+y-1;
            max = std::max(max, sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1]);
        }
    }
    return max;
}
