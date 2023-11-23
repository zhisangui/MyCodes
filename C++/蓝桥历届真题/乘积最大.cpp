/*#include <iostream>
#include <algorithm>
#define mod 1000000009
#define LL long long
using namespace std;

LL positive[100005];  // 存放正数
LL negative[100005];  //存放负数

int main(){
    LL n, k;
    cin >> n >> k;
    int numP = 0, numN = 0;//正数和负数个数
    LL temp;
    for(int i = 0; i < n; i++){
        cin >> temp;
        if(temp >= 0)
            negative[numN++] = temp;
        else 
            positive[numP++] = temp;
    }
    sort(positive, positive + numP);
    sort(negative, negative + numN, greater<int> ());
    numP--;
    numN--;
    LL ans = 1;
    for(int i = 0; i < k;){
        if(i + 2 < k){  // 至少还要两个数
            if(numP > 0 && numN > 0){   //正负都还至少有两个
                if(positive[numP] * positive[numP-1] < negative[numN] * negative[numN-1]){
                    ans = negative[numN] * negative[numN-1] * ans % mod;
                    numN -= 2;
                }          
                else{
                    ans = positive[numP] * positive[numP-1] * ans % mod;
                    numP -= 2;
                }    
                i += 2;
            }
            else if(numP <= 0 && numN > 0){  //正没有两个, 但负还有两个
                ans = negative[numP] * negative[numP - 1] * ans % mod;
                numP -= 2;
                i += 2;
            }
            else if(numP > 0 && numN <= 0){   ///负没有两个, 但正还有两个
                ans = positive[numP] * positive[numP-1] * ans % mod;
                numP -= 2;
                i += 2;
            }
            else if(numP == 0 && numN == 0 && i + 2 == k){    //正负都不到两个
                ans = positive[numP] * negative[numN] * ans % mod;
                numP--;
                numN--;
                i += 2;
            }
        }
        else if(i + 2 >= k){  //只要一个数
            if(numP != 0){
                ans = positive[numP] * ans % mod;
                numP--;
                i++;
            }
            else {
                ans = negative[numN] * ans % mod;
                numN--;
                i++;
            }
        }
    }
    cout << ans <<endl;
}
*/

#include <iostream>
#define mod 1000000009
#define LL long long
#include <algorithm>
using namespace std;

LL a[100005];

int main(){
    LL k, n;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a+1, a+1+n);
    LL ans = 1;
    int r = n, l = 1;
    LL sign = 1;
    if(k % 2){
        ans = a[n];
        r--;
        k--;
        if(ans < 0)
            sign = -1;
    }
    while(k)
    {
        if(a[l]*a[l+1]*sign < a[r]*a[r-1]*sign){
            ans = ans * a[r] * a[r-1] * sign % mod;
            r -= 2;
        }
        else{
            ans = ans * a[l] * a[l+1] * sign % mod;
            l += 2;
        }
        k -= 2;
    }
    cout << ans << endl;
}