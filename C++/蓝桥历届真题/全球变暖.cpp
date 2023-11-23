#include <cstdio>
using namespace std;

int cnt;
int n;
int fact;

char sea[1005][1005];
char sea2[1005][1005];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};


void dfs(int row, int col){
    // 判断每个连通块里是否有最终能存活的岛屿
    int k;
    for(k= 0; k < 4; k++){
        int nx = row + dx[k];
        int ny = col + dy[k];
        if(sea2[nx][ny] != '#')
            break;
    }
    if(k == 4)
        fact = 1;
        
    for(int i = 0; i < 4; i++){
        int nx = row + dx[i];
        int ny = col + dy[i];
        if(nx && ny && nx <= n && ny <= n && sea[nx][ny] == '#'){
            sea[nx][ny] = '.';
            dfs(nx, ny);     
        }
    }
}

int main(){
    scanf("%d", &n);
    getchar();
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            sea[i][j] = getchar();
            sea2[i][j] = sea[i][j];
        }
        getchar();
    }
    int end = 0; 
    
    /*   
    这样求的是最终的岛屿数量，这样与连通块相减的话，与题目不符，题目问的是照片中有多少岛屿会被完全淹没， 因此只要判断每个连通块里是否有最终能存活的岛屿即可
        for(int i = 2; i < n; i++)
        for(int j = 2; j < n; j++)
            if(sea[i][j] == '#' && sea[i-1][j] == '#' && sea[i+1][j] == '#' && sea[i][j+1] == '#' && sea[i][j-1] == '#')
                end++;
    */

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(sea[i][j] == '#'){
                sea[i][j] == '.';
                fact = 0;
                dfs(i, j);
                cnt++;
                if(fact)
                    end++;
            }
        }
    }
    printf("%d\n", cnt - end);
    return 0;
}