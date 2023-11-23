#include <cstdio>
const int mod = 1e9+7;
const int MAX = 5e7 + 3;
int a[MAX];
int n, m, idx;
int get_mid(int a[], int left, int right){
    int pivot = a[left];
    while(left < right){
        while(pivot < a[right] && left < right)
            right --;
        a[left] = a[right];
        while(pivot >= a[left] && left < right)
            left ++;
        a[right] = a[left];
    }
    a[left] = pivot;
    return left;
}
void QuickSort(int a[], int left, int right){
    if(left >= right)
        return;
    int mid = get_mid(a, left, right);
    if(mid == idx)      // 若mid与寻找的idx相等，返回其下标
        return;
    if(mid > idx)          // 若mid大于idx，说明idx在数组左边，对左边排序
        QuickSort(a, left, mid - 1);
    else            // 若mid小于idx，同理
        QuickSort(a, mid + 1, right);
}
int main(){
    scanf("%d %d %d", &n, &m, &idx);
    a[0] = 1;
    for(int i = 1; i <= n; i ++){
        a[i] = a[i-1] * 1ll * m % mod;
    }
    QuickSort(a, 1, n);
    printf("%d", a[idx]);
    return 0;
}