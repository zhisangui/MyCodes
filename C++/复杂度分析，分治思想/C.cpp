#include <cstdio>
const int MAX = 5e5+5;
long long cnt;
int a[MAX];
int temp[MAX];
void merge_sort(int left, int right){
    if(left == right)
        return;
    int mid = (left + right) >> 1;
    merge_sort(left, mid);
    merge_sort(mid + 1, right);
    for(int i = left, j = mid + 1, k = left; k <= right; k ++)
        if(j > right || (a[i] <= a[j] && i <= mid)) temp[k] = a[i++];
        else{
            temp[k] = a[j++];
            cnt += 1ll * mid - i + 1;     // 此行可计算逆序对数目，即mid后面的数若比mid前的数大，放到数组前面，并计数
        }
    for(int i = left; i <= right; ++i)
        a[i] = temp[i];
}
int main(){
    int n;
    cnt = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }
    merge_sort(0, n-1);
    /*for(int i = 0; i < n; i ++)
        printf("%d ", a[i]);*/
    printf("%lld", cnt);
    return 0;
}

