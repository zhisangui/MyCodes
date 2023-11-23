#include <cstdio>
void dfs(int x1, int y1, int gx, int gy, int length){
    if ((length == 2)){
        if(x1 == gx && y1 == gy)
            printf("%d %d 1\n", x1+1, y1+1);
        if(x1 == gx && y1+1 == gy)
            printf("%d %d 2\n", x1+1, y1);
        if(x1+1 == gx && y1 == gy)
            printf("%d %d 3\n", x1, y1+1);
        if(x1+1 == gx && y1+1 == gy)
            printf("%d %d 4\n", x1, y1);
        return;
    }
    if(gx <= length/2+x1-1 && gy <= length/2+y1-1){ //公主在左上
        printf("%d %d 1\n", length/2+x1, length/2+y1);
        dfs(x1, y1, gx, gy, length/2);
        dfs(x1, length/2+y1, length/2+x1-1, length/2+y1, length/2);
        dfs(length/2+x1, y1, length/2+x1, length/2+y1-1, length/2);
        dfs(length/2+x1, length/2+y1, length/2+x1, length/2+y1, length/2);
    }
    if(gx <= length/2+x1-1 && gy >= length/2+y1){ //公主在右上
        printf("%d %d 2\n", length/2+x1, length/2+y1-1);
        dfs(x1, length/2+y1, gx, gy, length/2);
        dfs(x1, y1, length/2+x1-1, length/2+y1-1, length/2);
        dfs(length/2+x1, y1, length/2+x1, length/2+y1-1, length/2);
        dfs(length/2+x1, length/2+y1, length/2+x1, length/2+y1, length/2);
    }
    if(gx >= length/2+x1 && gy <= length/2+y1-1){ //公主在左下
        printf("%d %d 3\n", length/2+x1-1, length/2+y1);
        dfs(length/2+x1, y1, gx, gy, length/2);
        dfs(x1, y1, length/2+x1-1, length/2+y1-1, length/2);
        dfs(x1, length/2+y1, length/2+x1-1, length/2+y1, length/2);
        dfs(length/2+x1, length/2+y1, length/2+x1, length/2+y1, length/2);
    }
    if(gx >= length/2+x1 && gy >= length/2+y1){ //公主在右下
        printf("%d %d 4\n", length/2+x1-1, length/2+y1-1);
        dfs(length/2+x1, length/2+y1, gx, gy, length/2);
        dfs(x1, y1, length/2+x1-1, length/2+y1-1, length/2);
        dfs(x1, length/2+y1, length/2+x1-1, length/2+y1, length/2);
        dfs(length/2+x1, y1, length/2+x1, length/2+y1-1, length/2);
    }
}
int main(){
    int k, x, y;
    scanf("%d %d %d", &k, &x, &y);
    dfs(1, 1, x, y, 1 << k);
    return 0;
}