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
void dfs(int row, int col, int index){
    for(int i = 0; i < 8; i ++){
        int nx = row + dx[i];
        int ny = col + dy[i];
        if(Judge(nx, ny)){
            region[nx][ny] = '*';
            dfs(nx, ny, 1);
        }
    }
}
int main(){
    while(scanf("%d %d", &n, &m) != EOF && m){
        count = 0;
        int cnt = 0;
        for(int i = 0; i < n; i ++){
            scanf("%s", region[i]);
        }
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m; j ++){
                if(region[i][j] == '@'){
                    region[i][j] = '*';
                    dfs(i, j, cnt ++); // 连通块，若需要求连通块数量，可以在main中先遍历，然后进行递归，在main中的递归的次数，即是连通块数量
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}