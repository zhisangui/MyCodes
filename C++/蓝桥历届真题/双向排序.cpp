#include <bits/stdc++.h>
using namespace std;

int a[5005];
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i){
        a[i] = i + 1;
    }
    int x, y;
    for(int i = 0; i < m; ++i){ 
        scanf("%d %d", &x, &y);
        if(x == 0)
            sort(a, a+y, greater<int>());
        else
            sort(a+y-1, a+n, less<int>());
    }
    for(int i = 0; i < n; ++i){
        printf("%d ",a[i]);
    }
    return 0;
}