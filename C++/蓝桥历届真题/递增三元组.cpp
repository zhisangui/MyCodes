#include <cstdio>
#include <algorithm>
using namespace std;

int a[100005], b[100005], c[100005];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++)
        scanf("%d", &b[i]);
    for(int i = 1; i <= n; i++)
        scanf("%d", &c[i]);
    long long ans = 0;
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    sort(c + 1, c + n + 1);
    for(int i = 1; i <= n; i++){
        long long numA = 0, numC = 0;
        for(int j = 1; j <= n; j++){
            if(a[j] < b[i])
                numA++;
            if(c[j] > b[i])
                numC++;
        }
        ans += numA * numC;
    }
    
    printf("%lld", ans);
}