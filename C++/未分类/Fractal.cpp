#include <cstdio>
#include <cstring>
const int dx[] = {2, 1, 0, 2};
const int dy[] = {0, 1, 2, 2};
char a[1000][1000];
void solve(int n){
    if(n == 1){
        a[n][n] = 'X';
        return;
    }
    solve (n - 1);
    int len = 1;
    for(int i = 1; i < n - 1; i ++)
        len *= 3;
    for(int i = 1; i <= len; i ++){
        for(int j = 1; j <= len; j ++){
            for(int k = 0; k < 4; k++){
                int nx = dx[k] * len + i;
                int ny = dy[k] * len + j;
                a[nx][ny] = a[i][j];
            }
        }
    }
}
int main(){
    int n;
    while (scanf("%d", &n) != EOF && n != -1)
    {
        std::memset(a, ' ', sizeof(a));
        solve(n);
        int len = 1;
        for(int i = 1; i < n; i ++)
            len *= 3;
    for(int i = 1; i <= len; i ++){
        for(int j = 1; j <= len; j ++){
            printf("%c", a[i][j]);
        }
        printf("\n");
    }
        printf("-\n");
    }
    return 0;
}