#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
bool vis[20][20];
int cnt;
int m, n, x, y;
int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};
void dfs(int x, int y, int count_uncoverd){
    if(count_uncoverd == 0){
        cnt ++;
    }
    else{
        for(int i = 0; i < 8; i ++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(!vis[nx][ny] && nx >= 0 && ny >= 0 && nx < n && ny < m ){
                vis[nx][ny] = true;
                dfs(nx, ny, count_uncoverd - 1);
                vis[nx][ny] = false;
            }
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t --)
    {
       memset(vis, 0, sizeof(vis));
       cin >> n >> m >> x >> y;  
       vis[x][y] = true;
       cnt = 0;
       dfs(x, y, m*n-1);
       cout << cnt << endl;
    }
    return 0;
}