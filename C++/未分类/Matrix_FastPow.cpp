#include <cstdio>
const int MAX = 105;
const int mod = 1e9+7;
int n;
long long k;
struct matrix{
    long long a[MAX][MAX] = {0};  // ��long long ��ֹ����
}A;
matrix Matrix_pow(matrix x, matrix y){
    matrix B;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
            for(int k = 0; k < n; k ++)
                B.a[i][j] = ( 1LL * B.a[i][j] + (x.a[i][k] % mod) * (y.a[k][j] % mod) ) % mod;
    return B;
}
int main(){
    scanf("%d %lld", &n, &k);
    matrix ret;
    //��ʼ��A
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
            scanf("%d", &A.a[i][j]);
    //����retΪ��λ����== ��λ�������������˵� ��1���� ����������ֵ���䣬 ��λ����Ϊ���ϵ����µĶԽ���Ϊ1������Ϊ0        
    for(int i = 0; i < n; i ++)
            ret.a[i][i] = 1;
    //������
    for(; k; k >>= 1){
        if(k & 1)
            ret = Matrix_pow(ret, A);
        A = Matrix_pow(A, A);
    }
    //��ӡ����
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++){
            if(j != n-1)
                printf("%d ", ret.a[i][j]);
            else    
                printf("%d\n", ret.a[i][j]);
        }
    }
    return 0;
}
