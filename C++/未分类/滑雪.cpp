#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
int snow[105][105];
int a[105][105];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int r, c;
int dfs(int x, int y){
    if(a[x][y])
        return a[x][y];
    for(int i = 0; i < 4; i ++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx <= r && nx >= 1 && ny <= c && ny >= 1 && snow[x][y] > snow[nx][ny]){
            a[x][y] = max(dfs(nx, ny) + 1, a[x][y]);
        }       
    }
    if(a[x][y] == 0)
        a[x][y] = 1;
    return a[x][y];
}
int main(){
    int ans = 0;
    scanf("%d %d", &r, &c);
    for(int i = 1; i <= r; i ++){
        for(int j = 1; j <= c; j ++){
            scanf("%d", &snow[i][j]);
        }
    }
    for(int i = 1; i <= r; i ++){
        for(int j = 1; j <= c; j ++){
            a[i][j] = dfs(i, j);
        }
    }
    for(int i = 1; i <= r; i ++){
        for(int j = 1; j <= c; j ++){
            ans = max(a[i][j], ans);
        }
    }
    printf("%d", ans);
    return 0;
}