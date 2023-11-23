#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
int main(){
    priority_queue < int, vector<int>, greater<int> > q;
    int n, x, sum = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i ++){
        scanf("%d", &x);
        q.push(x);
    }
    int a, b;
    for(int i = 1; i < n; i ++){
        a = q.top();
        q.pop();
        b = q.top();
        q.pop();
        q.push(a+b);
        sum += (a+b);
    }
    printf("%d", sum);
    return 0;
}