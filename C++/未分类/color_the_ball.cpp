#include <cstdio>
#include <cstring>
#define MAX int(1e5+5)
void modify(int l, int r);
void init(int t);
int a[MAX];
int diff[MAX];
int main(){
    int t;
    while(scanf("%d", &t) != EOF && t){
        memset(a, 0, sizeof(a));
        memset(diff, 0, sizeof(diff));
        int l, r;
        for(int i = 0; i < t; i ++){
            scanf("%d %d", &l, &r);
            modify(l, r);
        }
        init(t);
        for(int i = 1; i <= t; i++){
            if(i == t)
                printf("%d\n", a[i]);
            else
                printf("%d ", a[i]);
        }
    }
    return 0;
}
void modify(int l, int r){
    diff[l] += 1;
    diff[r+1] -= 1;
}
void init(int t){
    for(int i = 1; i <= t; i ++){
        a[i] = a[i-1] + diff[i];
    }
}