#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    long long n, c;
    vector <long long> a;
    cin >> n >> c;
    for(int i = 1; i <= n;  i++){
        int temp;
        cin >> temp;
        a.push_back(temp);
    }
    long long cnt = 0;
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++){
        long long x = a[i] + c;
        long long j = lower_bound(a.begin(), a.end(), x) - a.begin();//从数组的begin位置到end-1位置二分查找第一个大于或等于x的数字，找到返回该数字的地址，不存在则返回end。通过返回的地址减去起始地址begin,得到找到数字在数组中的下标。
        long long k = upper_bound(a.begin(), a.end(), x) - a.begin();//从数组的begin位置到end-1位置二分查找第一个大于x的数字，找到返回该数字的地址，不存在则返回end。通过返回的地址减去起始地址begin,得到找到数字在数组中的下标。
        cnt += k-j;
    }
    cout << cnt << endl;
    return 0;
}