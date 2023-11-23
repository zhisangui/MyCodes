#include <iostream>
#include <algorithm>
using namespace std;

int a[15][15];
int done[15][15];
int n, m;
int Sum, ans = 1e9;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

/*struct node{
    int x, y, cellNum, numSum;
int bfs(int x, int y){
    node temp;
    temp.x = x; 
    temp.y = y;
    temp.cellNum = 1;
    temp.numSum = a[x][y];
    queue<node> Q;
    Q.push(temp);
    while(Q.size()){
        node now = Q.front();
        Q.pop();
        if(now.numSum * 2 == sum){
            ans = now.cellNum;
            return 1;
        }
    }
}*/

void dfs(int x, int y, int sumNum, int cellNum){
    if(sumNum * 2 == Sum){
        ans = min(cellNum, ans);
        return;
    }
    if(sumNum * 2 > Sum || cellNum > ans)
        return;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx && ny && nx <= n && ny <= m && !done[nx][ny]){
            done[nx][ny] = 1;
            dfs(nx, ny, sumNum + a[nx][ny], cellNum + 1);
            done[nx][ny] = 0;
        }
    }
    return;
}

int main(){
    cin >> m >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
            Sum += a[i][j];
        }
    }
    dfs(1, 1, a[1][1], 1);
    if(ans == 1e9)
        cout << 0;
    else
        cout << ans;   
}