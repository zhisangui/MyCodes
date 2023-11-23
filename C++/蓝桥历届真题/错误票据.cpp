#include <iostream>
using namespace std;

int a[100005];

int main(){
    int n;
    cin >> n;
    int x;
    int gapNum, sameNum;
    while(cin >> x) {
        if(a[x])
            sameNum = x;
        a[x] = x;
    }
    for(int i = 1; i < 100005; i++){
        if(a[i] == 0 && a[i-1] && a[i+1])
            gapNum = i;
        /*if(a[i] == a[i+1] && a[i])
            sameNum = i;*/
    }
    cout << gapNum << ' ' << sameNum << endl;
}