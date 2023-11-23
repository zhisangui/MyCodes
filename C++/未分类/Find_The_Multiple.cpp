#include <cstdio>
#include <queue>
using namespace std;
long long n;
long long x;
void bfs(long long a){
    queue<long long> q;
    q.push(a);
    while(!q.empty()){
        x = q.front();
        if(x % n == 0)
            break;
        q.pop();
        /*if(x % 10 == 0){
            q.push(x * 10 * 1ll);
            q.push(x + 1 * 1ll);
        }
        else    
            q.push(x * 10 * 1ll);*/
        q.push(x * 10);
        q.push(x * 10 + 1);
    }
    
}   
int main(){
    while(scanf("%lld", &n) != EOF && n){
        bfs(1);
        printf("%lld\n", x);
    }
    return 0;
}