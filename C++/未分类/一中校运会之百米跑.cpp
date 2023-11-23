#include <cstdio>
#include <map>
#include <string>
#include <iostream>
using namespace std;
map <string, int> mp;
int f[20005];
int find(int x){
    if(x == f[x])
        return x;
    else    
        return f[x] = find(f[x]);
}
void join(int x, int y){
    int fx = find(x);
    int fy = find(y);
    if(fx != fy)
        f[fx] = fy;
}
int main(){
    int n, m, k;
    string x, y;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i ++){
        cin >> x;
        mp[x] = i;
        f[i] = i;
    }
    for(int i = 1; i <= m; i ++){
        cin >> x >> y;
        join(mp[x], mp[y]);
    }
    scanf("%d", &k);
    for(int i = 1; i <= k; i ++){
        cin >> x >> y;
        if(find(mp[x]) == find(mp[y]))
            printf("Yes.\n");
        else    
            printf("No.\n");
    }
    return 0;
}