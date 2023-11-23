#include <cstdio>
#include <algorithm>
using namespace std;

struct node{
    int time, id;
}a[100005];

bool cmp(const node &a, const node &b){
    return a.time < b.time;
}
int num[100005];
int ans[100005];

int main(){
    int n, d, k;
    scanf("%d %d %d", &n, &d, &k);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &a[i].time, &a[i].id);
    }
    sort(a, a+n, cmp);
    for(int i = 0, j = 0; i < n; i++){
        while(j < n && a[j].time - a[i].time < d){
            num[a[j].id]++;
            if(num[a[j].id] >= k)
                ans[a[j].id] = 1;
            j++;
        }
        num[a[i].id] --;
    }
    for(int i = 0; i <= 100000; i++){
        if(ans[i] == 1)
            printf("%d\n", i);
    }
}