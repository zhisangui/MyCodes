#include <cstdio>
#include <cstring>
#define MAX int(1e5+10)
using namespace std;
int a[MAX];
int sum[MAX];
int main(){
    int t;
    scanf("%d", &t);
    while (t--)
    {
        memset(a, 0, sizeof(a));
        memset(sum, 0, sizeof(sum));
        int n, m;
        int fact = 0;
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; i++){
            scanf("%d", &sum[i]);
            sum[i] += sum[i-1];
            if(!a[sum[i]%m]){
                a[sum[i]%m] = i;
            }
            else  
                fact = 1;
        }
        if(fact)
            printf("YES\n");
        else   
            printf("NO\n");
    }
    return 0;
}