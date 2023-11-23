#include <cstdio>
#include <stack>
using namespace std;
int main(){
    stack <int> stk;
    int n, x, count = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i ++){
        scanf("%d", &x);
        while(!stk.empty() && stk.top() > x)
            stk.pop();
        if(!stk.empty() && x == stk.top());
        else    
            if(x)
                count ++;
        stk.push(x);
    }
    printf("%d", count);
    return 0;
}
