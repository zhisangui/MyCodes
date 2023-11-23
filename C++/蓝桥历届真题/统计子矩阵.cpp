#include <cstdio>

int a[505][505];

int fact(int x1, int y1, int x2, int y2){
    return a[x2][y2] - a[x1-1][y2] - a[x2][y1-1] + a[x1-1][y1-1];
}

int main(){
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf("%d", &a[i][j]);
            a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
        }
    }
    long long ans = 0;
    for(int left = 1; left <= m; left++){
        for(int right = left; right <= m; right++){
            for(int up = 1, down = 1; down <= n; down++){
                while(up <= down && fact(up, left, down, right) > k) up ++;
                if(up <= down)
                    ans = ans + 1ll * (down - up +1);
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}
