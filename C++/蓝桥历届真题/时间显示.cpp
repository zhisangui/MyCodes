#include <bits/stdc++.h>
using namespace std;
int main(){
    long long time;
    cin >> time;// 49956
    time = time / 1000;
    long long hour = 0, minute = 0, second = 0;
    hour = time / 3600;
    hour %= 24;
    time %= 3600;
    minute = time / 60;
    time %= 60;
    second = time;
    printf("%02d:%02d:%02d", hour, minute, second);
}