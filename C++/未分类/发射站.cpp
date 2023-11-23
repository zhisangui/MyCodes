#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;
const int MAX = 1e6+5;
int a[MAX];
int f[MAX];
int sum[MAX];
int main(){
    stack <int> stk;
    int n, m = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++)
        scanf("%d %d", &a[i], &f[i]);
    for(int i = 1; i <= n; i ++){
        while(!stk.empty() && a[stk.top()] < a[i]){
            sum[i] += f[stk.top()];
            stk.pop();
        }
        if(!stk.empty())
            sum[stk.top()] += f[i];
        stk.push(i);
    }
    for(int i = 1; i <= n; i ++)
        m = max(m, sum[i]);
    printf("%d\n", m);
    return 0;
}