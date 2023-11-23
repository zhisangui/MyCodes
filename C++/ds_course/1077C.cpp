#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int>isParent(n+1, 0);
    for(int i = 0; i < n*(n-1)*(n-2); ++i)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if(d)
            isParent[c]++;
    }
    int ans = 1;
    for(int i = 2; i <= n; ++i)
        ans = isParent[i] > isParent[ans] ? i : ans;
    cout << ans << endl;
    return 0;
}