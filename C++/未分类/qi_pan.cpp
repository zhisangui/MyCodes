#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
char c[10][10];
int row[10];
int col[10];
int k, n, count;
void dfs(int num, int i){ 
    if(num == k)
        count ++;
    else{
        for(; i < n; i ++){  // i 不能每次递归都重新从0开始， 应该在当前行的后面， 这样才是深搜，否则就变成了组合数
            for(int j = 0; j < n; j ++){
                if((!row[i]) && (!col[j]) && c[i][j] == '#'){
                    row[i] = 1;
                    col[j] = 1;
                    dfs(num + 1, i + 1);
                    row[i] = 0;
                    col[j] = 0;
                }
            }
        } 
    }
}
int main(){
    while((scanf("%d %d", &n, &k) != EOF && (k != -1 ||  n != -1))){
        count = 0;
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        for(int i = 0; i < n; i ++)
            scanf("%s", c[i]);
        dfs(0, 0);
        printf("%d\n", count);
    }
}