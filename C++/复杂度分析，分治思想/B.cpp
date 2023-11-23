#include <cstdio>
const int MAX = 1e5+5;
int a[MAX];
int get_mid(int a[], int left, int right);
void quick_sort(int a[], int left, int right);
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i ++){
        scanf("%d", &a[i]);
    }
    quick_sort(a, 0, n -1);
    for(int i = 0; i < n - 1; i ++)
        printf("%d ", a[i]);
    printf("%d\n", a[n-1]);
    return 0;
}
int get_mid(int a[], int left, int right){
    int pivot = a[left];
    while(left < right){
        while(a[right] > pivot && left < right)
            right --;
        a[left] = a[right];
        while(a[left] <= pivot && left < right)
            left ++;
        a[right] = a[left];
    }
    a[left] = pivot;
    return left;
}
void quick_sort(int a[], int left, int right){
    if (right <= left)
        return;
    int mid = get_mid(a, left, right);
    quick_sort(a, left, mid - 1);
    quick_sort(a, mid+1, right);
}