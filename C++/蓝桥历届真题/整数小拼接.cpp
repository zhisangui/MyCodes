#include <iostream>
#include <algorithm>
#define LL long long
using namespace std;

LL a[100005];
LL num;

int main(){
    LL n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a+1, a+1+n);

    // 若a[i] 与 a[1] 拼接成的数比k大，则无须比较
    int Temp = a[1];
    int numTemp = 0;
    while(Temp){
        Temp /= 10;
        numTemp ++;
    }
    Temp = 1;
    for(int j = 0; j < numTemp; j++){
        Temp *= 10; 
    }
    for(int i = 1; i <= n; i++){
        if(a[i] * Temp + a[1] > k)
            continue;

        LL left = 1, right = n;
        while(left < right){
            LL mid = (left + right + 1) / 2;
            LL cnt = 0;
            LL temp = a[mid];
            while(temp){
                temp /= 10;
                cnt++;
            }
            LL x = 1;
            for(int i = 0; i < cnt; i++)
                x = 1ll * 10 * x;
            if(a[i] * x + a[mid] <= k)
                left = mid;
            else
                right = mid - 1;
        }
        num += right;
    }

    // 若一个数与它本身拼接的数符合条件，应该减去
    for(int i = 1; i <= n; i++){
        LL x = a[i];
        LL cnt = 0;
        while(x){
            x/=10;
            cnt++;
        }
        LL y = 1;
        for(int j = 0; j < cnt; j++)
            y = 1ll * 10 * y;
        if(a[i] * y + a[i] <= k)
            num --;
    }
    cout << num;
}