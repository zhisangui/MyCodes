#include <cstdio>
#include <algorithm>
#include <set>
#define MAX int(1e4+5)
using namespace std;
set <int> s;
int a[MAX];
int diff[MAX];
void modify(int l, int r);
int main(){
    int n, num, h, R;
    scanf("%d %d %d %d", &n, &num, &h, &R);
    while(R --){
        int l, r;
        scanf("%d %d", &l, &r);
        if(l>r) swap(l, r);
        if(s.count(l*MAX+r))
            continue;
        else{
            modify(l, r);
            s.insert(l*MAX+r);
        }
    }
    a[num] = h;
    for(int i = 1; i <= n; i ++){
        a[i] = a[i-1] + diff[i];
    }
    for(int i = 1; i <= n; i ++){
        a[i]+=h;
        printf("%d\n", a[i]);
    }
    return 0;
}
void modify(int l, int r){
    diff[l+1] -= 1;
    diff[r] += 1;
}
