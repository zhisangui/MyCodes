#include <cstdio>
#include <stack>
const int MAX = 3e6+5;
int a[MAX];
int f[MAX];
using namespace std;
int main(){
    stack <int> stk;
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++)
        scanf("%d", &a[i]);
    for(int i = 1; i <= n; i ++){
        while(!stk.empty() && a[stk.top()] < a[i]){
            f[stk.top()] = i;
            stk.pop();
        }
        stk.push(i);
    }
    for(int i = 1; i <= n; i ++)
        printf("%d ", f[i]);
    return 0;
}