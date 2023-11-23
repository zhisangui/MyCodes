#include <cstdio>
#include <cstring>
char region[105][105];
int n, m;
int count;
int dx[8] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[8] = {1, -1, 0, -1, 1, 0, -1, 1};
bool Judge(int nx, int ny){
    if(nx < n && nx >= 0 && ny < m && ny >= 0 && region[nx][ny] == '@')
        return true;
    return false;
}
void dfs(int row, int col){
    if(row == n - 1 && col == m - 1)
        return;
    for(; row < n; row ++){
        for(; col < m; col ++){
            if(region[row][col] == '@'){
                for(int i = 0; i < 8; i ++){
                    int nx = row + dx[i];
                    int ny = col + dy[i];
                    if(Judge(nx, ny)){
                        region[nx][ny] = '*';     // 在函数中递归，无法计算出连通块的数量
                        dfs(nx, ny);
                    }
                }
            }
        }
    }
}
int main(){
    while(scanf("%d %d", &n, &m) != EOF && m){
        count = 0;
        for(int i = 0; i < n; i ++){
            scanf("%s", region[i]);
        }
        dfs(0, 0);
    }
}