#include <cstdio>
#include <algorithm>
using namespace std;
int a[1005];
int dp[1005]; // dp[i]��ʾΪ��i��β�����е���������еĳ���
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    int res = 0;
    //dp[1] = 1;  ��˾����ʡ��
    for(int i = 1; i <= n; i ++){
        dp[i] = 1;            // �ô������Ӵ˾䣺a[1]���Ƚϴ�������Ƚ�ʱ����1��������3 3 1 2
        for(int j = 1; j < i; j ++){
            if(a[i] > a[j]){
                dp[i] = max(dp[j]+1, dp[i]);
            }
        }
        res = max(res, dp[i]);
    }
    printf("%d", res);
    return 0;
}