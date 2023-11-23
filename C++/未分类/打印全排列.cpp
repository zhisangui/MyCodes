#include <iostream>
#include <algorithm>
#define Swap(a, b) {int temp = a; a = b; b = temp;}
using namespace std;
int d[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int n;
void search(int idx, int x){
    if(idx == x){ //要求n个数打印x个数的全排列，则让idx = x即可，然后打印d的前x个
        for(int i = 1; i <= n; i ++)
            printf("%d", d[i]);
        printf(" ");
    }
    for(int i = idx; i <= x; i ++){
        Swap (d[idx], d[i]);
        search(idx + 1, x);
        Swap (d[i], d[idx]);
    }
}   
int main(){  
    cin >> n;
    int m;
    search(1, n);
}