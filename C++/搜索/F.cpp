#include <cstdio>
#include <queue>
using namespace std;

int n, k;
int vis[1000005];

struct way{
    int location, cnt;
};

void bfs(){
    way a;
    a.location = n;
    a.cnt = 0;
    queue<way> Q;
    Q.push(a);
    while(Q.size()){
        way now = Q.front();
        Q.pop();
        if(now.location == k){
            printf("%d\n", now.cnt);
            break;
        }
        else{
            way next;
            next.cnt = now.cnt + 1;
            next.location = now.location - 1;
            if(next.location >= 0 && next.location < 1000005 )
                if( vis[next.location] == 0){
                    Q.push(next);
                    vis[next.location] = 1;
                }
            next.cnt = now.cnt + 1;
            next.location = now.location + 1;
            if(next.location >= 0 && next.location < 1000005 )
                if(vis[next.location] == 0){
                    Q.push(next);
                    vis[next.location] = 1;
                }
            next.cnt = now.cnt + 1;
            next.location = now.location * 2;
            if(next.location >= 0 && next.location < 1000005 )
                if(vis[next.location] == 0){
                    Q.push(next);
                    vis[next.location] = 1;
                }
        }
    }
}

int main(){
    scanf("%d %d", &n, &k);
    bfs();
    return 0;
}

