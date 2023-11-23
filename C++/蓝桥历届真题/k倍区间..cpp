/*#include <cstdio>

long long a[100005];
long long num[100005];

int main(){
    int n, k;
    long long ans = 0;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
        a[i] += a[i-1];
        int x = a[i] % k;
        num[x] ++;
    }
    for(int i = 1; i <= n; i++){
        ans += num[i] * (num[i]-1) / 2;
    }
    ans += num[0];
    printf("%lld", ans);
}*/
#include <bits/stdc++.h>
using namespace std;
long long mod[100010]={0},add[100010]={0};
int main()
{
	int n,k,a;
	long long cnt=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		mod[i]=(mod[i-1]+a)%k;
		add[mod[i]]++;
	}
	for(int i=0;i<n;i++)
	{
		cnt+=add[i]*(add[i]-1)/2;//排列组合
	}
	cout<<cnt+add[0];
	return 0;
}