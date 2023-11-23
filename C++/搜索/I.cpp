#include <cstdio>
#include <queue>
using namespace std;

struct node{
    int x, y, val, prex, prey;
}maze[10][10];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool check(int x, int y){
    if(x <= 5 && y <= 5 && x && y && maze[x][y].val == 0){
        maze[x][y].val = 1;
        return true;
    }
    return false;
}

void bfs(int row, int col){
    node temp;
    temp.x = row, temp.y = col;
    queue<node> Q;
    Q.push(temp);
    while(Q.size()){
        node now = Q.front();
        Q.pop();
        if(now.x == 5 && now.y == 5){
            break;
        }
        for(int i = 0; i < 4; i++){
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];
            if(check(nx, ny)){
                node next;
                next.x = nx, next.y = ny;
                next.prex = now.x, next.prey = now.y;
                Q.push(next);
            }
        }
    }
}

void Print_Path(int x, int y){
    if(x == 1 && y == 1)
        printf("(0, 0)\n");
    else{
        if(x < 10 && x  && y < 10 && y)
            Print_Path(maze[x][y].prex, maze[x][y].prey);
        printf("(%d %d)\n", x-1, y-1);
    }
}

int main(){
    for(int i = 1; i <= 5; i++)
        for(int j = 1; j <= 5; j++){
            scanf("%d", &maze[i][j].val);
            maze[i][j].x = i;
            maze[i][j].y = j;
        }
    maze[1][1].prex = 0;
    maze[1][1].prey = 0;
    bfs(1, 1);
    Print_Path(5, 5);
    return 0;
    }