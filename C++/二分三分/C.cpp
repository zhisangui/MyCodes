#include <iostream>
using namespace std;
struct food{
    int h,w;
}foods[100005];
int main(){
    int n, k;
    cin >> n >> k;
    //int min = 100005;
    for(int i = 0; i < n; i ++){
        cin >> foods[i].h >> foods[i].w;
        /*if(foods[i].h < min)
            min = foods[i].h;
        if(foods[i].w < min)
            min = foods[i].w;*/
    }
    int l = 1, r = 1e6+5;
    while(l < r){
        //int mid = (l + r) >> 1;
        int mid = (l + r + 1) >> 1;
        int count = 0;
        for(int i = 0; i < n; i++){
            count += (foods[i].h / mid) * (foods[i].w / mid);
        }
        if(count >= k)
            l = mid;
        else    
            r = mid - 1;
    }
    cout << l << endl;
    return 0;
}
/*比如6x5，7x4的两块巧克力，切出来的最大块就是4*4。最小块肯定是1*1，

我的想法就是从4*4遍历到1*1，

比如4个小孩，两块巧克力6x5，7x4

4*4，能切2块，不够

3*3，能切3块，不够

2*2，能切12块，够了。2就是正确答案。

但是后来一想，

如果1个小孩，两块巧克力6x5，7x4，答案是5*5啊，因为7x4的巧克力可以不切，从4*4开始遍历就行不通了。

所以需要改变一下思路，从最长的边数开始切

7*7，能切0块，不够

6*6，能切0块，不够

5*5，能切1块，够了。5就是正确答案。*/