#include <cstdio>
const int MAX = 1e4+5;
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
    int m, n, z, x, y;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i ++)
        a[i] = i;
    for(int i = 0; i < m; i ++){
        scanf("%d %d %d", &z, &x, &y);
        if(z == 1)
            join(x , y);
        else
            if(find(x) == find(y))
                printf("Y\n");
            else    
                printf("N\n");
    }
    return 0;
}