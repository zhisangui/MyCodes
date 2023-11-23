#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char sa[1005];
char sb[1005];
int l[1005][1005];//sa的i与sb的j的最长,l的ij比sa和sb的大一
int main(){
    while(scanf("%s %s",sa, sb) != EOF){
        memset(l, 0, sizeof(l));
        int i,j;
        for(i = 0; sa[i] != '\0'; i ++){
            for(j = 0; sb[j] != '\0'; j ++){
                if(sa[i] == sb[j])
                    l[i+1][j+1] = l[i][j] + 1;
                else 
                    l[i+1][j+1] = max(l[i][j+1], l[i+1][j]);
            }
        }
        printf("%d\n", l[i][j]);
    }
    return 0;
}   