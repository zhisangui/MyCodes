#include <cstdio>
#include <cstring>
#include <algorithm>
const int maxn = 1005;
int f[maxn][maxn];
int val[maxn];
int v_bone[maxn];
void Print(int n, int v){                 // 打印背包物品：输出物品下标
    while(n){
        if(f[n][v] == f[n-1][v]){
            n--;
        }
        else{
            printf("%d ", n);
            v -= v_bone[n--];
        }
    }
    printf("\n");
}
int main(){
    int t;
    scanf("%d", &t);
    while(t --){
        memset(f, 0, sizeof(f));
        int n, v;
        scanf("%d %d", &n, &v);

        for(int i = 1; i <= n; i ++)
            scanf("%d", &val[i]);

        for(int i = 1; i <= n; i ++)
            scanf("%d", &v_bone[i]);

        for(int i = 1; i <= n; i ++){
            for(int j = 0; j <= v; j ++){
                f[i][j] = f[i - 1][j];
                if(j >= v_bone[i])
                    f[i][j] = std::max(f[i][j], f[i-1][j-v_bone[i]]+val[i]);
            }
        }
        printf("%d\n", f[n][v]);
        Print(n, v);
    }
    return 0;
}