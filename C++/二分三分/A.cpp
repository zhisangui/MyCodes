/*#include <iostream>
using namespace std;
int a[1000005];
int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++)
        cin >> a[i];
    int x;
    while(m --){
        cin >> x;
        int l = 1, r = n;
        while(l < r){
            int mid = (l+r) >> 1;
            if(a[mid] >= x) r = mid;
            else l = mid + 1;
        }
        if(a[l] == x)
            cout << l << ' ';
        else    
            cout << -1 << ' ';
    }
    return 0;
}*/
//手写二分版本

#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, m, a[N];

int main()
{
	scanf("%d%d",&n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	while(m--)
	{
		int x;
		scanf("%d",&x);
		int l = 1, r = n;
		while(l < r)
		{
			int mid = l + r >> 1;
			if (a[mid] < x) l = mid + 1;
			else r = mid; 
		}
		if (a[l] == x) printf("%d ", l);
		else printf("-1 ");
	}
}
