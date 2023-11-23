#include <cstdio>
#define LL long long
using namespace std;

int main(){
    LL n;
    scanf("%lld", &n);
    LL sum = 0;
    for(LL i = 1; i <= n; i++){
        LL x = i;
        LL cnt = 1;
        LL fact = 0;
        while(x){
            LL ans = x % 10;
            if(ans == 0 || ans == 2 || ans == 1 || ans == 9){
                fact = 1;
                break;
            }
            x /= 10;
        }
        if(fact)
            sum += i;
    }
    printf("%lld", sum);
    return 0;
}