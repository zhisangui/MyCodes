#include <cstdio>
const int MAX = 5e3+5;
int a[MAX];
int find(int x){
    if(a[x] == x)
        return x;
    else    
        return a[x] = find(a[x]);
}
void join(int x, int y){
    int fx = find(x);
    int fy = find(y);
    if(fx != fy)
        a[fx] = fy;
}
int main(){
    int n,m,p,x,y;
    scanf("%d %d %d", &n, &m, &p);
    for(int i = 1; i <= n; i ++)
        a[i] = i;
    for(int i = 0; i < m; i ++){
        scanf("%d %d", &x, &y);
        join(x , y);
    }
    for(int i = 0; i < p; i ++){
        scanf("%d %d", &x, &y);
        if(find(x) == find(y))
            printf("Yes\n");
        else    
            printf("No\n");
    }
    return 0;
}