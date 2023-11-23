#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
map <int, int> ma;
int find(int x){
    if(x == ma[x])
        return x;
    else 
        return ma[x] = find(ma[x]);
}
int main(){
    int boy_num, girl_num, p, q;
    scanf("%d %d %d %d", &boy_num, &girl_num, &p, &q);
    for(int i = 1; i <= boy_num; i ++)
        ma[i] = i;
    for(int i = -1; i >= (girl_num * -1); i --)
        ma[i] = i;
    int boy = 0, girl = 0;
    int x, y;
    for(int i = 1; i <= p; i ++){
        scanf("%d %d", &x, &y);
        if(find(x) != find(y)){
            ma[find(x)] = find(y);
        }
    }
    for(int i = 1; i <= q; i ++){
        scanf("%d %d", &x, &y);
        if(find(x) != find(y)){
            ma[find(x)] = find(y);
        }
    }
    for(int i = 1; i <= boy_num; i ++)
        if(find(i) == find(1))
            boy ++;
    for(int i = -1; i >= (girl_num * -1); i --)
        if(find(i) == find(-1))
            girl ++;
    printf("%d\n", min(boy, girl));
    return 0;
}