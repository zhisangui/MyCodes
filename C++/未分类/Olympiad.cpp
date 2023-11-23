#include <cstdio>
#include <cstring>
#define element_size int(1e5+5)
int a[element_size];
int num[10];
void init();
int qsum(int l, int r);
int Judge(int x);
int main(){
    int t;
    scanf("%d", &t);
    init();
    int l, r;
    while(t --){
        scanf("%d %d", &l, &r);
        printf("%d\n", qsum(l,r));
    }
    return 0;
}

void init(){
    memset(a, 0, sizeof(a));
    for(int i = 1; i <= element_size; i ++){
        a[i] = a[i-1] + Judge(i);
    }
}

int Judge(int x){
    memset(num, 0, sizeof(num));
    while(x > 0){
        if(!num[x%10])
            num[x%10] = 1;
        else
            return 0;
        x /= 10;
    }
    return 1;
}

int qsum(int l, int r){
    return a[r] - a[l - 1];
}