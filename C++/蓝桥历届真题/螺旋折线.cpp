#include <cstdio>
#include <cmath>
#include <map>
using namespace std;

map<int, map<int, int> >mp;

int main(){
    mp[0][0] = 0;
    mp[-1][0] = 1;
    mp[1][0] = 5;
    for(int i = 2; i <= 100005; i++){
        mp[-i][0] = mp[i-1][0] + 4 * (i-1) +1;
        mp[i][0] = mp[-i][0] + 4 * i;
    }
    int x, y;
    scanf("%d %d", &x, &y);
    if(!y){      //在x轴
        printf("%d", mp[x][y]);
        return 0;
    }
    if(x >= 0){         // 在x正半区
        if(abs(x) >= abs(y)){
            printf("%d", mp[x][0] + y);
        }
        else if(y > 0){
            printf("%d", mp[x+1][0] - y - 1);
        }
        else if(y < 0){
            printf("%d", mp[x+1][0] - y + 1);
        }
    }
    else if(x < 0){  //负半区
        if(y > 0){
            if(abs(x) >= abs(y)){
                printf("%d", mp[x][0] + y);
            }
            else {
                printf("%d", mp[x-1][0] + y + 1);
            }
        }
    }
    
}