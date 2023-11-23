#include <cstdio>
using namespace std;

int mp[105][105];

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        mp[a][b] = 1;
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                mp[i][j] = mp[i][j] || mp[i][k] && mp[k][j]; 
            }
        }
    }
    int count = 0;
    for(int i = 1; i <= n; i++){
        int cnt = 0;
        for(int j = 1; j <= n; j++){
            if(mp[i][j])
                cnt++;
            if(mp[j][i])
                cnt++;
        }
        if(cnt == n - 1)
            count++;
    }
    printf("%d", count);
}