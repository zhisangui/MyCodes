#include <bits/stdc++.h>
using namespace std;

int first[105], middle[105], last[105];
int res[100005];
int wei[10];
int a[105]; //回文
int n;
int ans;

int judge(int x){
    if(x <= n)
        return 0;
    int run = 0;
    int year = wei[8] * 1000 + wei[7] *100 + wei[6] * 10 + wei[5];
    if(year < 1000)
        return 0;
    int month = wei[4] * 10 + wei[3];
    int day = wei[2] * 10 + wei[1];
    if ( ( (year % 4 == 0) && (year % 100 !=0) ) || year % 400 == 0 )
        run = 1;  
    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
        if(day < 1 || day > 31)
            return 0;
    }
    if(month == 4 || month == 6 || month == 9 || month == 11){
        if(day < 1 || day > 30)
            return 0;
    }
    if(run){
        if(month == 2){
            if(day < 1 || day > 29)
                return 0;
        }
    }
    else{
        if(month == 2)
            if(day < 1 || day > 28)
                return 0;
    }
    for(int i = 1; i <= 8; ++i){
        if(wei[i] != wei[9-i])
            return 0;
    }
    return 1;
}

int main(){
    scanf("%d", &n);
    a[1] = 10100101;
    a[2] = 20200202;
    a[3] = 21211212;
    a[4] = 30300303;
    a[5] = 40400404;
    a[6] = 50500505;
    a[7] = 60600606;
    a[8] = 70700707;
    a[9] = 80800808;
    a[10] = 90900909;
    //找ab的答案
    if(a[1] > n)
        ans = a[1];
    else 
        for(int i = 1; i <= 10; ++i){ 
            if(a[i] <= n && a[i+1] > n){
                ans = a[i+1];
                break;
            }
        }

    for(int i = 1; i <= 9; ++i){
        middle[i] = i*1000+i;
    }
    middle[10] = 110, middle[11] = 1111, middle[12] = 2112;

    for(int i = 1; i <= 31; ++i){
        last[i] = i; 
    }

    for(int i = 1; i <= 9; i++){
        first[i] = i*10;
    }
    first[10] = 1;
    int x = 11;
    for(int i = 1; i <= 9; i++){
        first[x++] = i*10+1;
    }
    first[x++] = 2;
    for(int i = 1; i <= 9; i++){
        first[x++] = i*10+2;
    }
    a[30] = 3, a[31] = 13;

    int count = 1;
    for(int i = 1; i <= 31; i++){
        for(int j = 1; j <= 12; j++){
            res[count++] = first[i]*1000000 + middle[j]*100 + last[i];
        }
    }
    sort(res + 1, res + count + 1);
    for(int i = 1; i < count; i++){
        memset (wei, 0, sizeof(wei));
        int x = res[i];
        int y = 1;
        while(x){
            wei[y++] = x % 10;
            x /= 10;
        }
        if(judge(res[i])){
            printf("%d\n%d\n",res[i], ans);
            break;
        }
    }
    return 0;
} 