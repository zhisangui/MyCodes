// 一维差分

/*#include <stdio.h>
#define element_size 100
int diff[element_size];
int a[element_size];
void init(int n); //初始化a数组
void get_diff(int n); //初始化差分数组
void modify(int l, int r, int x); //修改差分数组
void update_a(int n); //更新数组a
int main(){
    int n;
    scanf("%d", &n);
    init(n);
    get_diff(n);
    int l, r, x;
    scanf("%d %d %d", &l, &r, &x);
    modify(l, r, x);
    update_a(n);
    for(int i = 1; i <= n; i++){
        printf("%d ", a[i]);
    }
    return 0;
}
void init(int n){
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
}
void get_diff(int n){
    for(int i = 1; i <= n; i++){
        diff[i] = a[i] - a[i - 1];
    }
}
void modify(int l, int r, int x){
    diff[l] += x;
    diff[r+1] -= x;
}
void update_a(int n){
    for(int i = 1; i <= n; i ++){
        a[i] = a[i-1] + diff[i];
    }
}*/


//二维差分

#include <stdio.h>
#include <cstring>
#define element_size 100
int a[element_size][element_size];
int diff[element_size][element_size];
int n, m;
void init(); //初始化a数组和diff数组
void modify(int x1, int y1, int x2, int y2, int c); //修改差分数组
void update_a(); //更新a数组

int main(){
    scanf("%d %d", &n, &m);
    init();
    int x1, y1, x2, y2, c;
    scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &c);
    modify(x1, y1, x2, y2, c);
    update_a();
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            printf("%d ", a[i][j]);
        }
    }
    return 0;
}

void init(){
    memset(a, 0, sizeof(a));
    memset(diff, 0, sizeof(diff));
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j++){
            scanf("%d", &a[i][j]);
            diff[i][j] = a[i][j] - a[i-1][j] - a[i][j-1] + a[i-1][j-1];
        }
    }
}

void modify(int x1, int y1, int x2, int y2, int c){
    diff[x1][y1] += c;
    diff[x1][y2+1] -= c; diff[x2+1][y1] -= c;
    diff[x2+1][y2+1] += c;
}

void update_a(){
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            a[i][j] = a[i-1][j] + a[i][j-1] - a[i-1][j-1] + diff[i][j];
        }
    }
}