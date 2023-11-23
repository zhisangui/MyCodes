#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int main(){
    int K, D, M, F;
    priority_queue < int, vector<int>, less<int> > k, d, m, f;
    scanf("%d %d %d %d", &K, &D, &M, &F);
    int x;
    int a, b, c;
    double sum;
    for(int i = 0; i < K; i ++)
        scanf("%d", &x), k.push(x);
    for(int i = 0; i < D; i ++)
        scanf("%d", &x), d.push(x);
    for(int i = 0; i < M; i ++)
        scanf("%d", &x), m.push(x);
    for(int i = 0; i < F; i ++)
        scanf("%d", &x), f.push(x);
    scanf("%d", &x);
    for(int i = 0; i < x; i ++){
        sum = 0;
        scanf("%d %d %d", &a, &b, &c);
        for(; a--;)
            sum += d.top(), d.pop();
        for(; b--;)
            sum += m.top(), m.pop();
        for(; c--;)
            sum += f.top(), f.pop();
        sum += k.top();
        k.pop();
        printf("%.2f\n", sum / 11.0);
    }
    return 0;
}