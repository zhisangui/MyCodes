#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

int vis[10005];
int done[10005];  // 标记已被搜索
int wei[5];
int a, b;
int res;
struct node{
    int num, cnt; // 当前数目，以及变换次数
};

void init(){
    for(int i = 1000; i <= 10000; i++){
        int fact = 1;
        for(int j = 2; j * j < i; j++){
            if(i % j == 0){
                fact = 0;
                break;
            }
        }
        if(fact){
            vis[i] = 1;
        }
    }
}

void bfs(int now, int ans){
    node temp;
    temp.cnt = 0, temp.num = now;
    queue<node> Q;
    Q.push(temp);
    while(Q.size()){
        node start = Q.front();
        Q.pop();
        if(start.num == ans){
            res = start.cnt;
            break;
        }
        if(done[start.num]) //已被搜索过
            continue;
        done[start.num] = 1;
        int y = start.num;
        int index = 1;
        while(y){
            wei[index++] = y % 10;
            y /= 10;
        }
        // push进新的四位素数
        for(int qian = 1;  qian <= 9; qian++){
            int v = qian*1000 + wei[3]*100 + wei[2] * 10 + wei[1];
            if(!done[v] && vis[v]){
                node u;
                u.cnt = start.cnt + 1;
                u.num = v;
                Q.push(u);
            }
        }
        for(int bai = 0;  bai <= 9; bai++){
            int v = bai*100 + wei[4]*1000 + wei[2] * 10 + wei[1];
            if(!done[v] && vis[v]){
                node u;
                u.cnt = start.cnt + 1;
                u.num = v;
                Q.push(u);
            }
        }
        for(int shi = 0;  shi <= 9; shi++){
            int v = shi*10 + wei[3]*100 + wei[4] * 1000 + wei[1];
            if(!done[v] && vis[v]){
                node u;
                u.cnt = start.cnt + 1;
                u.num = v;
                Q.push(u);
            }
        }
        for(int ge = 1;  ge <= 9; ge++){
            int v = ge + wei[3]*100 + wei[2] * 10 + wei[4] * 1000;
            if(!done[v] && vis[v]){
                node u;
                u.cnt = start.cnt + 1;
                u.num = v;
                Q.push(u);
            }
        }
    }
}

int main(){
    init();
    int t;
    scanf("%d", &t);
    while(t--){
        res = 0;
        memset(done, 0, sizeof(done));
        scanf("%d %d", &a, &b);
        if(a == b)
            printf("0\n");
        else{
            bfs(a, b);
            if(res)
                printf("%d\n", res);
            else
                printf("Impossible\n");
        }
    }
    return 0;
}