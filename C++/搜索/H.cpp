#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

char mp[205][205];
int n, m;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int doneY[205][205];
int idx;

struct res{
    int count;
    int cnt;
}ans[205][205];

struct node{
    int x, y, cnt;
}Y, M;

bool check(int x, int y){
    if(x && y && x <= n && y <= m && mp[x][y] != '#' && !doneY[x][y])
        return true;
    return false;
}

void bfs(int row, int col){
    node temp;
    doneY[row][col] = 1;
    temp.x = row, temp.y = col, temp.cnt = 0;
    queue<node> Q;
    Q.push(temp);
    while(Q.size()){
        node now = Q.front();
        Q.pop();
        for(int i = 0; i < 4; i++){
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];
            if(check(nx, ny)){
                node next;
                next.cnt = now.cnt + 1;
                next.x = nx;
                next.y = ny;
                doneY[nx][ny] = 1;
                if(mp[nx][ny] == '@'){
                    ans[nx][ny].cnt++;
                    ans[nx][ny].count += next.cnt;
                }
                Q.push(next);
            }
        }
    }
}

int main(){
    while(scanf("%d %d", &n, &m) != EOF){
        getchar();
        // 初始化
        int MIN = 0x3f3f3f3f;
        memset(mp, 0, sizeof(mp));
        memset(doneY, 0, sizeof(doneY));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                ans[i][j].cnt = 0;
                ans[i][j].count = 0;
            }
        }  
        //输入，并记录Y和M的位置
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m;j++){
                mp[i][j] = getchar();
                if(mp[i][j] == 'Y'){
                    Y.x = i, Y.y = j; 
                }
                if(mp[i][j] == 'M'){
                    M.x = i, M.y = j;
                }
            }
            getchar();
        }
        bfs(Y.x, Y.y);
        memset(doneY, 0, sizeof(doneY));
        bfs(M.x, M.y);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(ans[i][j].cnt == 2)
                    MIN = min(MIN, ans[i][j].count);
            }
        }
        printf("%d\n", MIN * 11);
    }
}