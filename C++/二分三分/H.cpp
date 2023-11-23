#include<cstdio>
#include<algorithm>
using namespace std;
int a[100005];
int main(){
    int n, m;
    while(scanf("%d %d", &n, &m) != EOF){
        int maxn = -1;
        for(int i = 1; i <= n; i ++){
            scanf("%d", &a[i]);
            maxn = max(maxn, a[i]);
        }
        int l = maxn, r = 1e9+5;
        while (l < r)
        {
            int mid = (l + r + 1) / 2;
            int cnt = 1;
            int ans = a[1]; 
            for(int i = 2; i <= n; i ++){
                if(ans + a[i] > mid){
                    cnt ++;
                    ans = a[i];
                }
                else{
                    ans += a[i];
                }
            }
            if(cnt > m)
                l = mid + 1;
            else
                r = mid - 1;
        }
        printf("%d\n", l);
    }
    return 0;
}